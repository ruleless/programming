#include "mqdef.h"

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_WRONLY);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct mq_attr mqattr;
	if (mq_getattr(mqdes, &mqattr) < 0)
		errQuit("get mq attr failed.");

	char *buff = new char[mqattr.mq_msgsize];
	for (int i = 1; i < argc; ++i)
	{
		snprintf(buff, mqattr.mq_msgsize, "%s", argv[i]);
		mq_send(mqdes, buff, strlen(buff), 0);
		printf("mq_send:%s\n", buff);
	}

	mq_close(mqdes);
	exit(0);
}
