#include "Trie.h"

struct Trie
{
	int n;
	struct Trie* child[MAX_BYTE_NUM];

	Trie()
	{
		n = 0;
		memset(child, 0, sizeof(child));
	}
};

void trie_insert(Trie *root, const char* word)
{
	Trie *ptr = root;
	int n = strlen(word);

	for (int i = 0; i < n; ++i)
	{
		unsigned char cur = (unsigned char)word[i];
		if (NULL == ptr->child[cur])
		{
			ptr->child[cur] = new Trie();
		}

		ptr = ptr->child[cur];
		if (i == n-1)
		{
			++ptr->n;
		}
	}
}

int trie_getword(Trie *root, const char *word)
{
	Trie *ptr = root;
	int n = strlen(word);

	for (int i = 0; i < n; ++i)
	{
		unsigned char cur = (unsigned char)word[i];
		if (NULL == ptr->child[cur])
		{
			return 0;
		}

		ptr = ptr->child[cur];
	}

	return n > 0 ? ptr->n : 0;
}

Trie* trie_new()
{
	return new Trie();
}

void trie_destroy(Trie *node)
{
	for (int i = 0; i < MAX_BYTE_NUM; ++i)
	{
		if (node->child[i])
		{
			trie_destroy(node->child[i]);
		}
	}
	delete node;
}
