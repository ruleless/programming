#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 505
int n;
bool edge[N][N];
struct Node
{
    int h;
    char sex[2],music[105],sport[105];
}node[N];

bool check(struct Node a,struct Node b)
{
    if( !(abs(a.h-b.h)>40||strcmp(a.sex,b.sex)==0||strcmp(a.music,b.music)!=0||strcmp(a.sport,b.sport)==0 ) )
        return true;
    return false;
}
bool vis[N];
int link[N];
bool Find(int a)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        if(edge[a][i]&&!vis[i])
        {
            vis[i]=true;
            if(link[i]==-1||Find(link[i]))
            {
                link[i]=a;
                return true;
            }
        }
    }
    return false;
}

int solve()
{
    int i,j,k=0;
    memset(link,-1,sizeof(link));
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
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%s%s%s",&node[i].h,node[i].sex,node[i].music,node[i].sport);
        }
        memset(edge,0,sizeof(edge));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j&&check(node[i],node[j]))
                {
                    edge[i][j]=true;
                }
            }
        }
        printf("%d\n",solve());
    }
    //while(1);
    return 0;
}
