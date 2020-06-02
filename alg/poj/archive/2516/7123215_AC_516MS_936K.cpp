#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int G[105][105],c[105][105],visited[105],dist[105],f[105][105],fw[105][105];
int tempm[55][55],tempn[55][55],tempk[55][55][55],pre[105];
int n,m;
#define MAX 1000000

int mcmf(int s,int t)
{
    int i,j,k;
    int flow=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        memset(pre,-1,sizeof(pre));
        queue<int>que;
        for(i=0;i<=m+n+1;i++)
        {
            dist[i]=MAX;
        }
        dist[s]=0;
        que.push(s);
        memset(visited,0,sizeof(visited));
        visited[s]=1;
        while(!que.empty())
        {
            k=que.front();
            que.pop();
            visited[k]=0;
            for(i=0;i<=m+n+1;i++)
            {
                if(c[k][i]>0&&dist[k]+fw[k][i]<dist[i])
                {
                    dist[i]=dist[k]+fw[k][i];
                    pre[i]=k;
                    if(!visited[i])
                    {
                        que.push(i);
                        visited[i]=1;
                    }
                }
            }
        }
        if(pre[t]==-1)
        {
            break;
        }
        j=t;
        i=pre[j];
        int min1=MAX;
        while(j!=s)
        {
            if(c[i][j]<min1)
            {
                min1=c[i][j];
            }
            j=i;
            i=pre[j];
        }
        j=t;
        i=pre[j];
        while(j!=s)
        {
            f[i][j]+=min1;
            f[j][i]=-f[i][j];
            c[i][j]=G[i][j]-f[i][j];
            c[j][i]=G[j][i]-f[j][i];
            flow+=fw[i][j]*min1;
            j=i;
            i=pre[j];
        }
    }
    for(i=m+1;i<=m+n;i++)
    {
        if(G[i][m+n+1]!=f[i][m+n+1])
        {
            return -1;
        }
    }
    return flow;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,K;
    while(scanf("%d%d%d",&n,&m,&K)!=EOF&&
    !(n==0&&m==0&&K==0) )
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=K;j++)
            {
                scanf("%d",&tempn[i][j]);
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=K;j++)
            {
                scanf("%d",&tempm[i][j]);
            }
        }
        for(k=1;k<=K;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    scanf("%d",&tempk[k][i][j]);
                }
            }
        }
        int flag=0;
        int ans=0;
        for(k=1;k<=K;k++)
        {
            memset(G,0,sizeof(G));
            for(i=1;i<=m;i++)
            {
                G[0][i]=tempm[i][k];
            }
            for(i=1;i<=n;i++)
            {
                G[i+m][m+n+1]=tempn[i][k];
            }
            for(i=1;i<=m;i++)
            {
                for(j=m+1;j<=m+n;j++)
                {
                    G[i][j]=MAX;
                }
            }
            memcpy(c,G,sizeof(G));
            memset(fw,0,sizeof(fw));
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    fw[j][i+m]=tempk[k][i][j];
                    fw[i+m][j]=-tempk[k][i][j];
                }
            }
            i=mcmf(0,m+n+1);
            if(i==-1)
            {
                flag=1;
                break;
            }
            else
            {
                ans+=i;
            }
        }
        if(flag)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
