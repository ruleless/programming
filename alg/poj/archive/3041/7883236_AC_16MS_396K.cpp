#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 505
int n,link[N];
bool edge[N][N],vis[N];

bool Find(int i)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(edge[i][j]&&!vis[j])
        {
            vis[j]=true;
            if(link[j]==-1||Find(link[j]))
            {
                link[j]=i;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int i,j,k=0;
    memset(link,-1,sizeof(link));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(Find(i))
            k++;
    }
    printf("%d\n",k);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        while(m--)
        {
            scanf("%d%d",&i,&j);
            edge[i][j]=true;
        }
        solve();
    }
    //while(1);
    return 0;
}
