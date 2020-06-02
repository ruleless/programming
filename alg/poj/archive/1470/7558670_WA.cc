#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define N 10000

vector<int>vec[N],query[N];
int n,parent[N],hash[N];
bool done[N];
int Find(int x)
{
    if(parent[x]==x)
        return x;
    int r=Find(parent[x]);
    parent[x]=r;
    return r;
}
void tarjan(int u)
{
    int i,j,k,v;
    int size=vec[u].size();
    for(i=0;i<size;i++)
    {
        v=vec[u][i];
        tarjan(v);
        parent[v]=u;
    }
    size=query[u].size();
    for(i=0;i<size;i++)
    {
        v=query[u][i];
        if(done[v])
        {
            //printf("yes\n");
            hash[Find(v)]++;
        }
        else
            query[v].push_back(u);
    }
    done[u]=true;
}
void solve(int root)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        parent[i]=i;
    memset(done,0,sizeof(done));
    memset(hash,0,sizeof(hash));
    tarjan(root);
    for(i=1;i<=n;i++)
    {
        if(hash[i])
            printf("%d:%d\n",i,hash[i]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,root;
    while(scanf("%d",&n)!=EOF)
    {
        int u;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&u);
            if(i==1)root=u;
            scanf(":(%d) ",&m);
            while(m--)
            {
                scanf("%d",&j);
                vec[u].push_back(j);
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf(" (%d %d) ",&i,&j);
            //printf("%d %d \n",i,j);
            query[i].push_back(j);
        }
        /*for(i=1;i<=n;i++)
        {
            int size=query[i].size();
            printf("%d:",i);
            for(j=0;j<size;j++)
                printf("%d ",query[i][j]);
            printf("\n");
        }*/
        solve(root);
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            query[i].clear();
        }
    }
    //while(1);
    return 0;
}
