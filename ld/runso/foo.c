#include <stdio.h>
#include <stdlib.h>


void foo_void()
{
    fprintf(stdout, "foo void\n");
}


int foo_int(int a)
{
    fprintf(stdout, "foo int\n");
    return a;
}
