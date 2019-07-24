
#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static jmp_buf jmpbuffer;

void jumpByCondition(char* str);

int main(int argc, char *argv[])
{
	const int s_maxBuffer = 256;
	char buff[s_maxBuffer];
	int val = 0;
	register int regVal = 0;
	volatile int volVal = 0;

	if (setjmp(jmpbuffer) != 0)
	{
		printf("error val=%d, regVal=%d, volVal=%d\n", val, regVal, volVal);
		exit(1);
	}

	while (fgets(buff, s_maxBuffer, stdin))
	{
		++val; ++regVal; ++volVal;
		jumpByCondition(buff);
	}

	exit(0);
}

void jumpByCondition(char* str)
{
	if (strstr(str, "jump") != NULL )
	{
		longjmp(jmpbuffer, 1);
	}
	else
	{
		int len = strlen(str);
		if (len - 1 > 0 && str[len - 1] == '\n')
			str[len - 1] = '\0';
		puts(str);
	}
}
