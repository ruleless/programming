#include "mqdef.h"

int main(int argc, char *argv[])
{
	mqd_t mqdes = mq_open(MQNAME, O_RDONLY);
	if (mqdes < 0)
		errQuit("open mq failed.");

	struct mq_attr attr;
	if (mq_getattr(mqdes, &attr) < 0)
		errQuit("get mq attr failed.");

	PRINT_INTVAL(attr.mq_maxmsg);
	PRINT_INTVAL(attr.mq_msgsize);
	PRINT_INTVAL(attr.mq_curmsgs);

	exit(0);
}
