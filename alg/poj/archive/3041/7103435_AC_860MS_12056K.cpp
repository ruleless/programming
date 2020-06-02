#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAXN 1006

int n,visited[MAXN],G[MAXN][MAXN],c[MAXN][MAXN],f[MAXN][MAXN],pre[MAXN];

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
        que.push(s);
        visited[s]=1;
        while(!que.empty())
        {
            k=que.front();
            que.pop();
            if(k==t)
            {
                break;
            }
            for(i=0;i<=2*n+1;i++)
            {
                if(!visited[i]&&c[k][i]>0)
                {
                    que.push(i);
                    pre[i]=k;
                    visited[i]=1;
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
    int m,i,j,k;
    scanf("%d%d",&n,&m);
    memset(G,0,sizeof(G));
    for(i=1;i<=n;i++)
    {
        G[0][i]=1;
    }
    for(i=n+1;i<=2*n;i++)
    {
        G[i][2*n+1]=1;
    }
    while(m--)
    {
        scanf("%d%d",&i,&j);
        G[i][n+j]=1;
    }
    /*for(i=0;i<=2*n+1;i++)
    {
        for(j=0;j<=2*n+1;j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }*/
    memcpy(c,G,sizeof(G));
    printf("%d\n",ek(0,2*n+1));
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
