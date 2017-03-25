#include "mqdef.h"

static int gFds[2];
static void sigUsr1(int signo)
{
	write(gFds[1], " ", 1);
}

int main(int argc, char *argv[])
{
	pipe(gFds);

	fd_set rset;
	FD_ZERO(&rset);
	FD_SET(gFds[0], &rset);

	struct sigaction sa;
	sa.sa_handler = sigUsr1;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		errQuit("set up signal failed.");

	mqd_t mqdes = mq_open(MQNAME, O_RDONLY|O_NONBLOCK);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct mq_attr attr;
	mq_getattr(mqdes, &attr);

	int msgCount = 0;
	char *buff = new char [attr.mq_msgsize];	
	memset(buff, 0, sizeof(char)*attr.mq_msgsize);

	struct sigevent ev;
	ev.sigev_notify = SIGEV_SIGNAL;
	ev.sigev_signo = SIGUSR1;
	mq_notify(mqdes, &ev);
	
	for (;;)
	{
		fd_set testSet = rset;
		int nready = select(gFds[0]+1, &testSet, NULL, NULL, NULL);

		if (nready < 0 && errno != EINTR)
			errQuit("select err.");			
		
		if (FD_ISSET(gFds[0], &testSet))
		{
			char c;
			read(gFds[0], &c, 1);
			unsigned int prio = 0;
			int n = 0;
			mq_notify(mqdes, &ev);
			while ((n = mq_receive(mqdes, buff, attr.mq_msgsize, &prio)) >= 0)
			{
				printf("recv %d (msglen=%d prio=%d):%s\n", ++msgCount, n, prio, buff);
				memset(buff, 0, sizeof(char)*attr.mq_msgsize);
			}

			if (n < 0 && errno != EAGAIN)
				errQuit("recv err.");
		}
	}
	
	exit(0);
}
