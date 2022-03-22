#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

char *trim(char *s)
{
    size_t n = strlen(s);
    char *lptr = s;
    while (isspace(*lptr)) lptr++;

    return s;
}

int main(int argc, char *argv[])
{
    char cmdbuf[1024] = {0};
    pid_t pid;

    while (1) {
        while (strlen(cmdbuf) == 0) {
            printf("minibash $ ");
            fgets(cmdbuf, sizeof(cmdbuf), stdin);
        }

        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed, reason: %s", strerror(errno));
            exit(1);
        }

        if (pid == 0) { // child process
            if (execlp(cmdbuf, 0) < 0) {
                fprintf(stderr, "exec %s failed, reason: %s", cmdbuf, strerror(errno));
                exit(1);
            }
        }

        // parent process
        int status = 0;
        waitpid(pid, &status, 0);
        fprintf(stderr, "%d exit, status: %d\n", (int)pid, status);
    }

    return 0;
}
