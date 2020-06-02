#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000000

int N,M,G[155][155],f[155][155],fw[155][155],c[155][155],tempn[155][155],tempm[155][155],pre[155],visited[155],dist[155];
int ff[155][155];

int ek(int s,int t)
{
    int i,j,k,flow=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        queue<int>que;
        memset(visited,0,sizeof(visited));
        memcpy(ff,fw,sizeof(fw));
        que.push(s);
        memset(visited,0,sizeof(visited));
        visited[s]=1;
        for(i=0;i<=M+N+1;i++)
        {
            dist[i]=MAX;
        }
        dist[s]=0;
        while(!que.empty())
        {
            k=que.front();
            que.pop();
            visited[k]=0;
            for(i=0;i<=M+N+1;i++)
            {
                if(c[k][i]>f[k][i]&&dist[k]+ff[k][i]<dist[i])
                {
                    dist[i]=dist[k]+ff[k][i];
                    pre[i]=k;
                    if(!visited[i])
                    {
                        que.push(i);
                        visited[i]=1;
                    }
                }
            }
        }
        if(dist[t]==MAX)
        {
            break;
        }
        j=t;
        i=pre[j];
        int min1=1<<30;
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
            j=i;
            i=pre[j];
            flow+=min1*fw[i][j];
        }
    }
    for(i=M+1;i<=M+N;i++)
    {
        if(f[i][M+N+1]!=G[i][M+N+1])
        {
            return -1;
        }
    }
    return flow;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int K,i,j,k,ans;
    while(scanf("%d%d%d",&N,&M,&K)!=EOF&&!(N==0&&M==0&&K==0))
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=K;j++)
                scanf("%d",&tempn[i][j]);
        }
        for(i=1;i<=M;i++)
        {
            for(j=1;j<=K;j++)
                scanf("%d",&tempm[i][j]);
        }
        int flag=1;
        ans=0;
        for(k=1;k<=K;k++)
        {
            memset(fw,0,sizeof(fw));
            int temp;
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++)
                {
                    scanf("%d",&temp);
                    fw[j][M+i]=temp;
                    fw[M+i][j]=-temp;
                }
            }
            for(i=1;i<=M;i++)
            {
                fw[0][i]=0;
            }
            for(i=M+1;i<=M+N;i++)
            {
                fw[i][M+N+1]=0;
            }
            memset(G,0,sizeof(G));
            for(i=1;i<=M;i++)
            {
                G[0][i]=tempm[i][k];
            }
            for(i=1;i<=M;i++)
            {
                for(j=1;j<=N;j++)
                {
                    G[i][j+M]=tempm[i][j];
                }
            }
            for(i=1;i<=N;i++)
            {
                G[M+i][M+N+1]=tempn[i][k];
            }
            memcpy(c,G,sizeof(G));
            if(flag)
            {
                i=ek(0,M+N+1);
                if(i==-1)
                {
                    flag=0;
                    ans=-1;
                    continue;
                }
                else
                {
                    ans+=i;
                }
            }
        }
        printf("%d\n",ans);
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
