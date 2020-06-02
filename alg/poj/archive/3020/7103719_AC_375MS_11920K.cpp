#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
#define MAXN 1000

int n,visited[MAXN],f[MAXN][MAXN],c[MAXN][MAXN],G[MAXN][MAXN],pre[MAXN];
int node[44][14],flag[44][14];
char str[44][14];

struct Mov
{
    int x,y;
}mov[5]={{-1,0},{0,-1},{1,0},{0,1}};

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
    int i,j,k,T,h,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&h,&w);
        for(i=0;i<h;i++)
        {
            scanf("%s",str[i]);
        }
        memset(flag,0,sizeof(flag));
        n=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(str[i][j]=='*')
                {
                    flag[i][j]=1;
                    node[i][j]=++n;
                }
            }
        }
        memset(G,0,sizeof(G));
        for(i=1;i<=n;i++)
        {
            G[0][i]=1;
        }
        for(i=n+1;i<=2*n;i++)
        {
            G[i][2*n+1]=1;
        }
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(flag[i][j])
                {
                    for(k=0;k<4;k++)
                    {
                        int x=i+mov[k].x;
                        int y=j+mov[k].y;
                        if( (x>=0&&x<h)&&(y>=0&&y<w) )
                        {
                            if(flag[x][y])
                            {
                                G[node[i][j]][node[x][y]+n]=1;
                            }
                        }
                    }
                }
            }
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
        printf("%d\n",(2*n-ek(0,2*n+1))/2);
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
