#include "mqdef.h"

static bool gSigFlag = false;
static void sigUsr1(int signo)
{
	gSigFlag = true;
}

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_RDONLY|O_NONBLOCK);
	if (mqdes < 0)
		errQuit("open mq failed.");

	// 设置信号处理程序
	struct sigaction newSa, oldSa;
	newSa.sa_handler = sigUsr1;
	newSa.sa_flags = 0;
	sigemptyset(&newSa.sa_mask);

	if (sigaction(SIGUSR1, &newSa, &oldSa) < 0)
		errQuit("sigaction failed.");

	// 为本进程注册消息队列非空的通知
	struct sigevent ev;
	ev.sigev_notify = SIGEV_SIGNAL;
	ev.sigev_signo = SIGUSR1;

	mq_notify(mqdes, &ev);

	// 接收缓冲区
	struct mq_attr attr;
	mq_getattr(mqdes, &attr);
	char *buff = new char [attr.mq_msgsize];
	unsigned int prio = 0;
	int msgCount = 0;
	memset(buff, 0, sizeof(char)*attr.mq_msgsize);

	sigset_t newMask, oldMask, zeroMask;
	sigemptyset(&newMask);
	sigaddset(&newMask, SIGUSR1);
	sigemptyset(&zeroMask);
	for (;;)
	{
		sigprocmask(SIG_BLOCK, &newMask, &oldMask);
		while (!gSigFlag)
		{
			printf("suspend.\n");
			sigsuspend(&zeroMask);
		}
		printf("comming.\n");

		mq_notify(mqdes, &ev);
		int n = 0;
		while((n=mq_receive(mqdes, buff, attr.mq_msgsize, &prio)) >= 0)
		{
			printf("recv %d (msglen=%d prio=%d): %s\n", ++msgCount, n, prio, buff);
			memset(buff, 0, sizeof(char)*attr.mq_msgsize);
		}

		if (errno != EAGAIN)
		{
			errQuit("recv err.");
		}
		gSigFlag = false;

		printf("end reading.\n");
		sigprocmask(SIG_SETMASK, &oldMask, NULL);
	}

	delete []buff;

	sigaction(SIGUSR1, &oldSa, NULL);
	exit(0);
}
