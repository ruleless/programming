#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTE_NUM ((unsigned char)(-1)+1)

struct Trie;
typedef struct Trie Trie;

void trie_insert(Trie *root, const char* word);
int trie_getword(Trie *root, const char *word);

Trie* trie_new();
void trie_destroy(Trie *node);
