#include "mqdef.h"

int main(int argc, char *argv[])
{
	int res = mq_unlink(MQNAME);
	if (res < 0)
		errQuit("unlink mq failed.");
	printf("unlink %s success.\n", MQNAME);
	exit(0);
}
