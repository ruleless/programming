#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAXN 150

int n,c[MAXN][MAXN],f[MAXN][MAXN],G[MAXN][MAXN],pre[MAXN],visited[MAXN];

int ek(int s,int t)
{
    int i,j,k,flow=0;
    memset(f,0,sizeof(f));
    queue<int>que;
    while(1)
    {
        while(!que.empty())
        {
            que.pop();
        }
        memset(visited,0,sizeof(visited));
        visited[s]=1;
        que.push(s);
        k=0;
        while(!que.empty())
        {
            k=que.front();
            que.pop();
            if(k==t)
            {
                break;
            }
            for(i=0;i<=n+1;i++)
            {
                if(!visited[i]&&c[k][i]>0)
                {
                    que.push(i);
                    visited[i]=1;
                    pre[i]=k;
                }
            }
        }
        if(k!=t)
        {
            break;
        }
        int min1=1<<30;
        j=t;
        i=pre[j];
        while(j!=s)
        {
            if(c[i][j]<min1)
            {
                min1=c[i][j];
            }
            j=i;
            i=pre[j];
        }
        flow+=min1;
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
        }
    }
    return flow;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    char ss[20];
    int flag[MAXN],i,j,k,m,np,nc;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        memset(G,0,sizeof(G));
        while(m--)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d,%d)%d",&i,&j,&k);
            G[i][j]=k;
        }
        while(np--)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&i,&j);
            G[n][i]=j;
        }
        while(nc--)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&i,&j);
            G[i][n+1]=j;
        }
        memcpy(c,G,sizeof(G));
        /*for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",ek(n,n+1));
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
