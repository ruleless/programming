#include <stdio.h>
#include <stdlib.h>


static int add(int a, int b)
{
    asm volatile("addl %%ebx, %%eax"
                 : "=a"(b)
                 : "b"(a), "a"(b)
                 );

    return b;
}


static int add_atomic(int a, int b)
{
    asm volatile("lock\n\t"
                 "addl %1, %0"
                 : "=m"(b)
                 : "r"(a), "m"(b)
                 );

    return b;
}


int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "must input two number\n");
        exit(1);
    }

    printf("%s + %s = %d\n",
           argv[1], argv[2],
           add(atoi(argv[1]), atoi(argv[2])));

    printf("%s + %s = %d (by atomic add)\n",
           argv[1], argv[2],
           add_atomic(atoi(argv[1]), atoi(argv[2])));

    exit(0);
}
