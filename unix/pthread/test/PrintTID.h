
#ifndef __PRINTTID_H__
#define __PRINTTID_H__

#include "Thread.h"

class ThreadPrintTID : public Thread {
public:
	virtual bool run();
};

#endif
