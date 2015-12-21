#include "mqdef.h"

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_RDONLY);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct mq_attr attr;
	if (mq_getattr(mqdes, &attr) < 0)
		errQuit("get mq attr faield.");

	int msgCount = 0;
	char *buff = new char [attr.mq_msgsize];
	for (;;)
	{
		unsigned int prio = 0;
		memset(buff, 0, sizeof(char)*attr.mq_msgsize);
		int len = mq_receive(mqdes, buff, attr.mq_msgsize, &prio);
		if (len < 0)
		{
			break;
		}

		printf("recv %d(prio=%d msglen=%d):%s\n", ++msgCount, prio, len, buff);
	}

	mq_close(mqdes);
	exit(0);
}
