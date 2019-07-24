#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int daemon()
{
	// fork process
    switch (fork())
	{
    case -1:
		fputs("fork failed!\n", stderr);
        return -1;
    case 0:
        break;
    default:
		exit(0);
    }

	// create session
    if (setsid() == -1)
	{
        return -1;
    }

	// dup stdin/stdout/stderr to null
    umask(0);

    int fd = open("/dev/null", O_RDWR);
    if (fd == -1)
	{
        return -1;
    }

    if (dup2(fd, STDIN_FILENO) == -1)
	{
        return -1;
    }

    if (dup2(fd, STDOUT_FILENO) == -1)
	{
        return -1;
    }

#if 0
    if (dup2(fd, STDERR_FILENO) == -1)
	{
        return -1;
    }
#endif

    if (fd > STDERR_FILENO)
	{
        if (close(fd) == -1)
		{
            return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
	daemon();

	pid_t pid = getpid();
	char log[256] = {0};
	while (1)
	{
		snprintf(log, sizeof(log), "pid=%d  ppid=%d\n", pid, getppid());
		fputs(log, stderr);
		sleep(1);
	}
    return 0;
}

