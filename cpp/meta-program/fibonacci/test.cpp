#include "fibonacci.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("fibo(0) = %d\n", Fibonacci<0>::N);
    printf("fibo(1) = %d\n", Fibonacci<1>::N);
    printf("fibo(2) = %d\n", Fibonacci<2>::N);
    printf("fibo(3) = %d\n", Fibonacci<3>::N);
    printf("fibo(4) = %d\n", Fibonacci<4>::N);
    printf("fibo(5) = %d\n", Fibonacci<5>::N);
    printf("fibo(6) = %d\n", Fibonacci<6>::N);
    printf("fibo(7) = %d\n", Fibonacci<7>::N);
    printf("fibo(100) = %d\n", Fibonacci<46>::N);
    exit(0);
}
