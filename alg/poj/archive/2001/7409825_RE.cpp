#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char str[2016][56],n;

struct Trie
{
    struct Trie* child[26],*par;
    int cnt;//出现的次数
    Trie()
    {
        par=NULL;cnt=1;
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
            struct Trie* node=new struct Trie;
            node->par=cur;
            cur->child[s[i]-'a']=node;
            cur=node;
        }
        else
        {
            cur=cur->child[s[i]-'a'];
			++cur->cnt;
        }
    }
}

void Find(char *s,char* ans)
{
    int i,j,k=0,len=strlen(s);
	char tmp[26];
    struct Trie*cur=root;
    for(i=0;i<len;i++)
    {
        cur=cur->child[s[i]-'a'];
    }
	while(cur->par->cnt==1)
	{
		k++;
		cur=cur->par;
	}
	for(i=0;i<len-k;i++)
	{
		tmp[i]=s[i];
	}
	tmp[i]='\0';
	strcpy(ans,tmp);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
	char ans[26];
    n=0;
    root=new struct Trie;root->cnt=2;
    while(scanf("%s",ans)!=EOF)
	{
		insert(ans);
		strcpy(str[n++],ans);
	}
    for(i=0;i<n;i++)
    {
        Find(str[i],ans);
        printf("%s %s\n",str[i],ans);
    }
    //while(1);
    return 0;
}
