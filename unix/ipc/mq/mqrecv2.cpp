#include "mqdef.h"

static void sigUsr1(int signo) {}

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_RDONLY|O_NONBLOCK);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct sigaction newSa, oldSa;
	newSa.sa_handler = sigUsr1;
	newSa.sa_flags = 0;
	sigemptyset(&newSa.sa_mask);
	sigaction(SIGUSR1, &newSa, &oldSa);

	sigset_t maskSig;
	sigemptyset(&maskSig);
	sigaddset(&maskSig, SIGUSR1);
	sigprocmask(SIG_BLOCK, &maskSig, NULL);

	struct sigevent ev;
	ev.sigev_notify = SIGEV_SIGNAL;
	ev.sigev_signo = SIGUSR1;

	mq_notify(mqdes, &ev);

	struct mq_attr attr;
	int msgCount = 0;
	mq_getattr(mqdes, &attr);
	char *buff = new char [attr.mq_msgsize];
	memset(buff, 0, sizeof(char)*attr.mq_msgsize);
	
	for (;;)
	{
		int signo;
		sigwait(&maskSig, &signo);
		if (signo == SIGUSR1)
		{
			mq_notify(mqdes, &ev);
			
			unsigned int prio = 0;
			int n = 0;
			while ((n = mq_receive(mqdes, buff, attr.mq_msgsize, &prio)) >= 0)
			{
				printf("recv %d (msglen=%d  prio=%d): %s\n", ++msgCount, n, prio, buff);
				memset(buff, 0, sizeof(char)*attr.mq_msgsize);
			}
			
			if (errno != EAGAIN)
				errQuit("recv err.");
		}
	}

	delete []buff;
	buff = NULL;
	
	exit(0);
}
