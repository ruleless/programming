#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <openssl/crypto.h>
#include <openssl/safestack.h>

#define MAX_N 10000

#define sk_Foo_new(cmp) SKM_sk_new(Foo, (cmp))
#define sk_Foo_new_null() SKM_sk_new_null(Foo)
#define sk_Foo_free(st) SKM_sk_free(Foo, (st))
#define sk_Foo_num(st) SKM_sk_num(Foo, (st))
#define sk_Foo_value(st, i) SKM_sk_value(Foo, (st), (i))
#define sk_Foo_set(st, i, val) SKM_sk_set(Foo, (st), (i), (val))
#define sk_Foo_zero(st) SKM_sk_zero(Foo, (st))
#define sk_Foo_push(st, val) SKM_sk_push(Foo, (st), (val))
#define sk_Foo_unshift(st, val) SKM_sk_unshift(Foo, (st), (val))
#define sk_Foo_find(st, val) SKM_sk_find(Foo, (st), (val))
#define sk_Foo_find_ex(st, val) SKM_sk_find_ex(Foo, (st), (val))
#define sk_Foo_delete(st, i) SKM_sk_delete(Foo, (st), (i))
#define sk_Foo_delete_ptr(st, ptr) SKM_sk_delete_ptr(Foo, (st), (ptr))
#define sk_Foo_insert(st, val, i) SKM_sk_insert(Foo, (st), (val), (i))
#define sk_Foo_set_cmp_func(st, cmp) SKM_sk_set_cmp_func(Foo, (st), (cmp))
#define sk_Foo_dup(st) SKM_sk_dup(Foo, st)
#define sk_Foo_pop_free(st, free_func) SKM_sk_pop_free(Foo, (st), (free_func))
#define sk_Foo_deep_copy(st, copy_func, free_func) SKM_sk_deep_copy(Foo, (st), (copy_func), (free_func))
#define sk_Foo_shift(st) SKM_sk_shift(Foo, (st))
#define sk_Foo_pop(st) SKM_sk_pop(Foo, (st))
#define sk_Foo_sort(st) SKM_sk_sort(Foo, (st))
#define sk_Foo_is_sorted(st) SKM_sk_is_sorted(Foo, (st))

typedef struct
{
    int n;
} Foo;

int foo_cmp(const Foo * const *a, const Foo * const *b)
{
    return (*a)->n - (*b)->n;
}

int main(int argc, char *argv[])
{
    int n = 100, i, r;
    Foo *foo;

    if (argv[1])
        n = atoi(argv[1]);

    CRYPTO_malloc_debug_init();
    MemCheck_start();

    STACK_OF(Foo) *foo_st;
    foo_st = sk_Foo_new(foo_cmp);
    for (i = 0; i < n; i++)
    {
        r = rand();
        foo = OPENSSL_malloc(sizeof(Foo));
        foo->n = r % MAX_N;
        sk_Foo_push(foo_st, foo);
    }

    while ((foo = sk_Foo_pop(foo_st)))
    {
        printf("%d ", foo->n);
        OPENSSL_free(foo);
    }
    putchar('\n');

    sk_Foo_free(foo_st);

    CRYPTO_mem_leaks_fp(stderr);
    exit(0);
}
