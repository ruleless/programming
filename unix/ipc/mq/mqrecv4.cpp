#include "mqdef.h"

static void threadFunc(sigval_t val);
static int gMsgCount = 0;

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_RDONLY|O_NONBLOCK);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct sigevent ev;
	ev.sigev_notify = SIGEV_THREAD;
	ev.sigev_value.sival_int = mqdes;
	ev.sigev_notify_function = &threadFunc;
	ev.sigev_notify_attributes = NULL;
	if (mq_notify(mqdes, &ev) < 0)
		errQuit("set notify failed.");

	for (;;)
		pause();
	
	exit(0);
}

static void threadFunc(sigval_t val)
{
	int mqdes = val.sival_int;
	struct mq_attr attr;
	mq_getattr(mqdes, &attr);

	char *buff = new char [attr.mq_msgsize];
	unsigned int prio = 0;
	int n = 0;
	while ((n = mq_receive(mqdes, buff, attr.mq_msgsize, &prio)) >= 0)
	{
		printf("recv %d (msglen=%d prio=%d):%s\n", ++gMsgCount, n, prio, buff);
	}

	if (n < 0 && errno != EAGAIN)
		errQuit("recv err.");
}
