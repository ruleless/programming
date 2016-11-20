#include "mqdef.h"

struct mq_attr attr;

int main(int argc, char *argv[])
{
	int maxMsg = 0;
	int msgSize = 0;

	if (argc > 1)
		maxMsg = atoi(argv[1]);
	if (argc > 2)
		msgSize = atoi(argv[2]);
	
	attr.mq_maxmsg = maxMsg;
	attr.mq_msgsize = msgSize;
	
	mqd_t mqdes = mq_open(MQNAME, O_RDWR|O_CREAT|O_EXCL, 0644, attr.mq_maxmsg ? &attr : NULL);
	if (mqdes < 0)
		errQuit("create MQ failed.");

	printf("create mq:%s success.\n", MQNAME);
	mq_close(mqdes);
	exit(0);
}
