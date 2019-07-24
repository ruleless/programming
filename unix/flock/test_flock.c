#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/file.h>

#define USE_FLOCK 0
#define MAX_CHILDREN 10
#if MAX_CHILDREN
# define MAX_THREADS 0
#else
# define MAX_THREADS 5
#endif

#define FLOCK "/tmp/test_flock"

int reg_flock(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;
	lock.l_pid = 0;
	return fcntl(fd, cmd, &lock);
}

int reg_flock_ex(int fd, int cmd, int type)
{
    struct flock lock;
	lock.l_type = type;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	lock.l_pid = 0;
	return fcntl(fd, cmd, &lock);
}

void test_flock(int fd)
{
    int trytimes = 0;
    int newfd;

try_again:
#if USE_FLOCK
    // newfd = open(FLOCK, O_RDWR|O_CREAT, 0664);
    // if (flock(fd, LOCK_EX) == 0)
    newfd = dup(fd);
    if (flock(newfd, LOCK_EX) == 0)
#else
    if (reg_flock_ex(fd, F_SETLKW, F_WRLCK) == 0)
#endif
    {
        fprintf(stdout, "pid %d acquire write lock ok!\n", (int)getpid());
        // sleep(1);
#if USE_FLOCK
        flock(newfd, LOCK_UN);
#else
        reg_flock_ex(fd, F_SETLKW, F_UNLCK);
#endif
    }
    else
    {
        if (trytimes++ < 5)
        {
            fprintf(stderr, "pid %d acquire write lock failed, %s, try again!\n",
                    (int)getpid(), strerror(errno));
            sleep(1);
            goto try_again;
        }
        else
        {
            fprintf(stderr, "pid %d acquire write lock failed, %s, now exit!\n",
                    (int)getpid(), strerror(errno));
        }
    }
}

void *thread_proc(void *arg)
{
    int fd = (int)arg;
    test_flock(fd);

    return NULL;
}

int main(int argc, char *argv[])
{
    int fd, newfd;
    int childcount = 0;
    int i, trytimes = 0;
#if MAX_CHILDREN
    pid_t pid, children[MAX_CHILDREN] = {(pid_t)0};
#endif
#if MAX_THREADS
    pthread_t threads[MAX_THREADS] = {(pthread_t)0};
#endif

    fd = open(FLOCK, O_RDWR|O_CREAT, 0664);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failed, %s\n", FLOCK, strerror(errno));
        exit(1);
    }

    if (argc > 1)
    {
        int opt = 0;
        while ((opt = getopt(argc, argv, "ul")) != -1)
        {
            switch (opt)
            {
            case 'u':
                reg_flock_ex(newfd, F_SETLKW, F_UNLCK);
                fprintf(stderr, "unlock\n");
                break;
            case 'l':
                {
                    struct flock lock;
                    lock.l_type = F_WRLCK;
                    lock.l_start = 0;
                    lock.l_whence = SEEK_SET;
                    lock.l_len = 0;
                    lock.l_pid = 0;
                    if (fcntl(fd, F_GETLK, &lock) == 0)
                    {
                        fprintf(stderr, "lock type:%d pid:%d\n", lock.l_type, (int)lock.l_pid);
                    }
                }
                break;
            default:
                break;
            }
        }
        exit(0);
    }

#if MAX_CHILDREN
    // test process
    for (i = 0; i < MAX_CHILDREN; i++)
    {
        if ((pid = fork()) == 0)
        {
            test_flock(fd);
            exit(0);
        }
        else if (pid > 0)
        {
            children[childcount++] = pid;
        }
    }
#endif

#if MAX_THREADS
    // test thread
    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_proc, (void *)fd);
    }
#endif

#if MAX_THREADS
    // wait thread
    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
#endif

#if MAX_CHILDREN
    test_flock(fd);
    fprintf(stderr, "main thread exiting ...\n");

    // wait process
    i = 0;
    while (i < childcount)
    {
        if (waitpid(children[i], NULL, 0) < 0)
        {
            fprintf(stderr, "wait %d failed, reason:%s, continue ...\n", strerror(errno));
            continue;
        }

        children[i++] = 0;
    }
#endif

    exit(0);
}
