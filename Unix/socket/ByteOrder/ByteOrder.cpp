
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union ByteOrder {
	ushort n;
	char s[2];
};

int main(int argc, char *argv[])
{
	ByteOrder b;
	b.n = 0x0201;
	if (b.s[0] == 1)
		printf("小端序\n");
	else if (b.s[0] == 2)
		printf("大端序\n");
	else
		printf("Error\n");
	return 0;
}
