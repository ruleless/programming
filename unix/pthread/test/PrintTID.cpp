
#include "PrintTID.h"
#include <stdio.h>

bool ThreadPrintTID::run() {
	unsigned int tid = (unsigned int)mTID;
	printf("pid=%d  tid=%u(0x%08x)\n", (int)getpid(), tid, tid);
	return true;
}
