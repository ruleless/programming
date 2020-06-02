#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int parent[550000],n,deg[550000];
struct Trie
{
    struct Trie* child[26];
    int node;
    Trie()
    {
        node=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
}*root;

int Find(int x)
{
    if(parent[x]<0)
        return x;
    int r=Find(parent[x]);
    parent[x]=r;
    return r;
}
void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b)
        parent[a]=b;
}

void insert(char* s)
{
    int i,j,k,len=strlen(s);
    struct Trie* cur=root;
    for(i=0;i<len;i++)
    {
        if(cur->child[s[i]-'a']==NULL)
            cur->child[s[i]-'a']=new struct Trie;
        cur=cur->child[s[i]-'a'];
        if(i==len-1)
        {
            if(cur->node==0)
                cur->node=++n;
            deg[cur->node]++;
        }
    }
}

int search(char* s)
{
    int i,j,k,len=strlen(s);
    struct Trie* cur=root;
    for(i=0;i<len;i++)
    {
        cur=cur->child[s[i]-'a'];
    }
    return cur->node;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k;
    char s1[20],s2[20];n=0;
    memset(parent,-1,sizeof(parent));
    memset(deg,0,sizeof(deg));
    root=new struct Trie;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        insert(s1);
        insert(s2);
        int x=search(s1),y=search(s2);
        Union(x,y);
    }
    
    k=Find(1);
    for(i=2;i<=n;i++)
    {
        if(k!=Find(i))
            break;
    }
    if(i<=n)
    {
        printf("Impossible\n");
    }
    else
    {
        k=0;
        for(i=1;i<=n;i++)
            if(deg[i]%2==1)
                k++;
        if(k==0||k==2)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    //while(1);
    return 0;
}
