#include <stdio.h>
#include <stdlib.h>


/*
 * asm(assembler template
 *     : output operands                // optional
 *     : input operands                 // optional
 *     : list of clobbered registers    // optional
 *    );
 */


static void swap(int a, int b)
{
    fprintf(stdout, "before swap, a=%d, b=%d\n", a, b);

    asm("movl %2, %%eax\n\t"
        "movl %3, %0\n\t"
        "movl %%eax, %1"
        : "=r"(a), "=r"(b)
        : "r"(a), "r"(b)
        : "%eax"
        );

    fprintf(stdout, "after swap, a=%d, b=%d\n", a, b);
}


int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "must input two number\n");
        exit(1);
    }

    swap(atoi(argv[1]), atoi(argv[2]));

    exit(0);
}
