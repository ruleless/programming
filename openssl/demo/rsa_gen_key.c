#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>

int main(int argc, char *argv[])
{
    BIO *bio = BIO_new_fp(stdout, BIO_NOCLOSE | BIO_FP_TEXT);
    RSA *rsa = RSA_new();

    rsa = RSA_generate_key(2048, 3, NULL, NULL);

    RSA_print(bio, rsa, 0);

    RSA_free(rsa);
    exit(0);
}

