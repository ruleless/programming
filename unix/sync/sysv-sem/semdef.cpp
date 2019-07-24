#include "semdef.h"

void errQuit()
{
	printf("%s\n", strerror(errno));
	exit(1);
}
