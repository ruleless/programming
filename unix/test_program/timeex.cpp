#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int main(int argc, char *argv[])
{
	struct timeval begT;
	gettimeofday(&begT, NULL);
	// uint64_t begT = getTimeStamp();
	
	char programName[NAME_MAX] = "timeex";
	if (argc > 1)
	{
		strncpy(programName, argv[1], sizeof(programName)-1);

		pid_t pid = fork();
		if (pid == 0)
		{
			if (execvp(argv[1], argv+1) < 0)
			{
				errSys("run failed.");
			}
		}
		waitpid(pid, NULL, 0);
	}

	struct timeval endT;
	gettimeofday(&endT, NULL);
	// uint64_t endT = getTimeStamp();

	// printf("(%s) run time:%lldms\n", programName, (endT-begT)*1000./CLOCKS_PER_SEC);
	// printf("(%s) run time:%dms\n", programName, (endT-begT)/FREQUENCY);

	int64_t diffMSec = (endT.tv_sec-begT.tv_sec)*1000 + (endT.tv_usec-begT.tv_usec)/1000;
	printf("[%s] run %lldms\n", programName, diffMSec);
	
	exit(0);
}
