#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/crypto.h>

#define MAX_N 16
#define MIN_MEM 16
#define MAX_MEM 256

int main(int argc, char *argv[])
{
    int i, r;

    CRYPTO_malloc_debug_init();
    MemCheck_start();

    srand(time(NULL));
    for (i = 0; i < MAX_N; i++)
    {
        r = rand() % (MAX_MEM - MIN_MEM) + MIN_MEM;
        OPENSSL_malloc(r);
    }

    CRYPTO_mem_leaks_fp(stderr);
    exit(0);
}

