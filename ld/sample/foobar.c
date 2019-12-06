#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int global_init_var = 84;
int global_uninit_var;


void func(int n)
{
    printf("%d\n", n);
}


int main(int argc, char *argv[])
{
    static int static_init_var = 85;
    static int static_uninit_var;

    int a = 1;
    int b;

    func(static_init_var + static_uninit_var + a + b);

    exit(0);
}
