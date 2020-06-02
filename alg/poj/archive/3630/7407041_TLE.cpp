#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Trie
{
    struct Trie *child[10];
    bool flag;
}*root;

bool insert(char* s)
{
    int i,j,k;
    int len=strlen(s);
    struct Trie* cur=root;
    for(i=0;i<len;i++)
    {
        if(cur->child[s[i]-'0']==NULL)
        {
            struct Trie* node=new struct Trie;
            for(j=0;j<10;j++)
            {
                node->child[j]=NULL;
            }
            if(i==len-1)
            {
                node->flag=true;
            }
            else
            {
                node->flag=false;
            }
            cur->child[s[i]-'0']=node;
            cur=node;
        }
        else
        {
            cur=cur->child[s[i]-'0'];
            if(cur->flag)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t,n;
    char s[15];bool flag;
    scanf("%d",&t);
    while(t--)
    {
        root=new struct Trie;
        for(i=0;i<10;i++)
        {
            root->child[i]=NULL;
            root->flag=false;
        }
        scanf("%d",&n);
        flag=true;
        while(n--)
        {
            scanf("%s",s);
            if(flag)
            {
                if(!insert(s))
                {
                    flag=false;
                }
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    //while(1);
    return 0;
}
