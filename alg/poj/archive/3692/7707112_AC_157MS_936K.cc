#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 500

bool edge[MAXN][MAXN],vis[MAXN];
int girl,boy,n,link1[MAXN];

bool Find(int a)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        if(edge[a][i]&&!vis[i])
        {
            vis[i]=true;
            if(link1[i]==-1||Find(link1[i]))
            {
                link1[i]=a;
                return true;
            }
        }
    }
    return false;
}
int solve()
{
    int i,j,k=0;
    memset(link1,-1,sizeof(link1));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(Find(i))
            k++;
    }
    return n-k/2;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,cse=0;
    while(scanf("%d%d%d",&girl,&boy,&m)!=EOF&&girl+boy+m)
    {
        memset(edge,0,sizeof(edge));
        for(i=1;i<=girl;i++)
        {
            for(j=1;j<=boy;j++)
            {
                edge[i][j+girl]=true;
                edge[j+girl][i]=true;
            }
        }
        while(m--)
        {
            scanf("%d%d",&i,&j);
            edge[i][j+girl]=false;
            edge[j+girl][i]=false;
        }
        n=girl+boy;
        int res=solve();
        printf("Case %d: %d\n",++cse,res);
    }
    return 0;
}