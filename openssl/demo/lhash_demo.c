#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/lhash.h>

#define MAX_N 16
#define KEY_SIZE 64
#define VAL_SIZE 256

#define lh_KEYVALUE_new() LHM_lh_new(KEYVALUE, keyvalue)
#define lh_KEYVALUE_insert(lh, inst) LHM_lh_insert(KEYVALUE, lh, inst)
#define lh_KEYVALUE_retrieve(lh, inst) LHM_lh_retrieve(KEYVALUE, lh, inst)
#define lh_KEYVALUE_delete(lh, inst) LHM_lh_delete(KEYVALUE, lh, inst)
#define lh_KEYVALUE_doall(lh, fn) LHM_lh_doall(KEYVALUE, lh, fn)
#define lh_KEYVALUE_doall_arg(lh, fn, arg_type, arg) LHM_lh_doall_arg(KEYVALUE, lh, fn, arg_type, arg)
#define lh_KEYVALUE_error(lh) LHM_lh_error(KEYVALUE, lh)
#define lh_KEYVALUE_num_items(lh) LHM_lh_num_items(KEYVALUE, lh)
#define lh_KEYVALUE_down_load(lh) LHM_lh_down_load(KEYVALUE, lh)
#define lh_KEYVALUE_node_stats_bio(lh, out) LHM_lh_node_stats_bio(KEYVALUE, lh, out)
#define lh_KEYVALUE_node_usage_stats_bio(lh, out)  LHM_lh_node_usage_stats_bio(KEYVALUE, lh, out)
#define lh_KEYVALUE_stats_bio(lh, out) LHM_lh_stats_bio(KEYVALUE, lh, out)
#define lh_KEYVALUE_free(lh) LHM_lh_free(KEYVALUE, lh)

typedef struct
{
    char key[KEY_SIZE];
    char val[VAL_SIZE];
} KEYVALUE;

static unsigned long keyvalue_hash(const KEYVALUE *n)
{
    return lh_strhash(n->key);
}

static int keyvalue_cmp(const KEYVALUE *a, const KEYVALUE *b)
{
    return strcmp(a->key, b->key);
}

static IMPLEMENT_LHASH_HASH_FN(keyvalue, KEYVALUE);
static IMPLEMENT_LHASH_COMP_FN(keyvalue, KEYVALUE);

static void traverse(void *n, void *arg)
{
    LHASH_OF(KEYVALUE) *lh = (LHASH_OF(KEYVALUE) *)arg;
    KEYVALUE *k = lh_KEYVALUE_delete(lh, (KEYVALUE *)n);

    if (k)
    {
        fprintf(stdout, "delete %s:%s\n", k->key, k->val);
        free(k);
    }
}

int main(int argc, char *argv[])
{
    LHASH_OF(KEYVALUE) *lh;
    KEYVALUE tmp;
    KEYVALUE *current, *prev, *target;
    int i, r;

    srand(time(NULL));
    lh = lh_KEYVALUE_new();
    for (i = 0; i < MAX_N; i++)
    {
        current = (KEYVALUE *)malloc(sizeof(KEYVALUE));
        r = rand() % MAX_N;
        snprintf(current->key, sizeof(current->key), "key_%d", r);
        snprintf(current->val, sizeof(current->val), "val_%d", r);
        if ((prev = lh_KEYVALUE_insert(lh, current)))
        {
            fprintf(stderr, "exits %s:%s\n", prev->key, prev->val);
            free(prev);
        }
    }

    fprintf(stdout, "insert %lu items!\n", lh_KEYVALUE_num_items(lh));
    snprintf(tmp.key, sizeof(tmp.key), "key_1");
    if ((target = lh_KEYVALUE_retrieve(lh, &tmp)))
    {
        fprintf(stdout, "found %s, v:%s\n", target->key, target->val);
    }
    else
    {
        fprintf(stderr, "not found %s\n", tmp.key);
    }

    lh_KEYVALUE_doall_arg(lh, &traverse, LHASH_OF(KEYVALUE), lh);
    fprintf(stdout, "left %lu items\n", lh_KEYVALUE_num_items(lh));

    lh_KEYVALUE_free(lh);
    exit(0);
}
