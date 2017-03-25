
#include "PrintTID.h"

bool ThreadPrintTID::run() {
	pthread_t tid = pthread_self();
	unsigned int utid = (unsigned int)tid;
	printf("pid:%u  tid:%u(0x%08x)\n", getpid(), utid, utid);
	return true;
}
