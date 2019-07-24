#include "mytype.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("int: %d\n", Type2ID<int>::ID);
    printf("unsigned int: %d\n", Type2ID<unsigned int>::ID);
    printf("long: %d\n", Type2ID<long>::ID);
    return 0;
}
