#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAXBUF 1024

int main(int argc, char **argv)
{
    int sockfd, new_fd;
    socklen_t len;
    struct sockaddr_in serv_addr, peer_addr;
    unsigned int serv_port;
    char buf[MAXBUF + 1];
    SSL_CTX *ctx;

    if (argv[1])
        serv_port = atoi(argv[1]);
    else
        serv_port = 7838;

    /* SSL 库初始化 */
    SSL_library_init();

    /* 载入所有 SSL 算法 */
    OpenSSL_add_all_algorithms();

    /* 载入所有 SSL 错误消息 */
    SSL_load_error_strings();

    /* 以 SSL V2 和 V3 标准兼容方式产生一个 SSL_CTX */
    ctx = SSL_CTX_new(SSLv23_server_method());

    if (!ctx)
    {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    /* 载入用户的数字证书，此证书用来发送给客户端。证书里包含有公钥 */
    if (SSL_CTX_use_certificate_file(ctx, argv[4], SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    /* 载入用户私钥 */
    if (SSL_CTX_use_PrivateKey_file(ctx, argv[5], SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    /* 检查用户私钥是否正确 */
    if (!SSL_CTX_check_private_key(ctx))
    {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    /* 开启一个 socket 监听 */
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    else
    {
        printf("create server socket %d!\n", sockfd);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_port = htons(serv_port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("bind error");
        exit(1);
    }
    else
    {
        printf("bind server addr!\n");
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("listen");
        exit(1);
    }

    for (;;)
    {
        SSL *ssl;

        len = sizeof(struct sockaddr);

        /* 等待客户端连上来 */
        if ((new_fd = accept(sockfd, (struct sockaddr *) &peer_addr, &len)) == -1)
        {
            perror("accept");
            exit(errno);
        }
        else
        {
            printf("server: got connection from %s, port %d, socket %d\n",
                   inet_ntoa(peer_addr.sin_addr),
                   ntohs(peer_addr.sin_port), new_fd);
        }

        /* 基于 ctx 产生一个新的 SSL */
        ssl = SSL_new(ctx);

        /* 将连接用户的 socket 加入到 SSL */
        SSL_set_fd(ssl, new_fd);

        /* 建立 SSL 连接 */
        if (SSL_accept(ssl) == -1)
        {
            perror("accept");
            close(new_fd);
            break;
        }

        /* 开始处理每个新连接上的数据收发 */
        memset(buf, 0, sizeof(buf));
        strcpy(buf, "server->client");

        /* 发消息给客户端 */
        len = SSL_write(ssl, buf, strlen(buf));

        if (len <= 0)
        {
            printf("send \"%s\" error! errno=%d(%s)",
                   buf, errno, strerror(errno));
            goto finish;
        }
        else
        {
            printf("send \"%s\" success!", buf);
        }

        /* 接收客户端的消息 */
        memset(buf, 0, sizeof(buf));
        len = SSL_read(ssl, buf, MAXBUF);
        if (len > 0)
        {
            printf("recv msg:\"%s\" msglen=%d", buf, len);
        }
        else
        {
            printf("recv failed! errno=%d(%s)", errno, strerror(errno));
        }

        /* 处理每个新连接上的数据收发结束 */
  finish:
        /* 关闭 SSL 连接 */
        SSL_shutdown(ssl);

        /* 释放 SSL */
        SSL_free(ssl);

        /* 关闭 socket */
        close(new_fd);
    }

    /* 关闭监听的 socket */
    close(sockfd);

    /* 释放 CTX */
    SSL_CTX_free(ctx);

    return 0;
}
