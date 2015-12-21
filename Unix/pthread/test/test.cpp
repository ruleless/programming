
#include "PrintTID.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_THREADS 10

int main(int argc, char* argv[]) {
	pthread_t tids[MAX_THREADS] = {0};
	ThreadPrintTID printThreads[MAX_THREADS];
	memset(tids, 0, sizeof(tids));
	
	for (int i = 0; i < MAX_THREADS; ++i) {
		printThreads[i].start();
		if (printThreads[i].getStatus() == Thread::S_Running) {
			tids[i] = printThreads[i].getThreadID();
		}
	}

	for (int i = 0; i < MAX_THREADS; ++i) {
		if (tids[i] != 0) {
			pthread_join(tids[i], NULL);
		}
	}
	
	exit(0);
}
