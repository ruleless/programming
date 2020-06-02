#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char str[1016][26];
int n;

struct Trie
{
    struct Trie* child[26];
    int cnt;
    Trie()
    {
        cnt=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
}*root;

void insert(char *s)
{
    int i,j,k,len=strlen(s);
    struct Trie* cur=root;
    for(i=0;i<len;i++)
    {
        if(cur->child[s[i]-'a']==NULL)
        {
            cur->child[s[i]-'a']=new struct Trie;
        }
        cur=cur->child[s[i]-'a'];
		++cur->cnt;
    }
}

void Find(char *s)
{
    int i,j,k=0,len=strlen(s);
    struct Trie*cur=root;
    for(i=0;i<len;i++)
    {
        if(cur->cnt==1)break;
		printf("%c",s[i]);
		cur=cur->child[s[i]-'a'];
    }

	printf("\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
	char ans[26];
    n=0;
    root=new struct Trie;root->cnt=2;
    while(scanf("%s",str[n])!=EOF)
	{
		insert(str[n]);
		n++;
	}
    for(i=0;i<n;i++)
    {
		printf("%s ",str[i]);
        Find(str[i]);
        
    }
    //while(1);
    return 0;
}
