/*
Edmonds Karp算法求最大流 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999

int G[N][N],c[N][N],f[N][N],pre[N],que[N],n,vis[N];

int ek(int s,int t)
{
    int i,j,k,head,tail,flow=0;
    memset(f,0,sizeof(f));
    while(true)
    {
        head=tail=0;
        memset(vis,0,sizeof(vis));
        que[tail++]=s;
        vis[s]=true;
        while(head<tail)
        {
            k=que[head++];
            if(k==t)
                break;
            for(i=1;i<=n;i++)
            {
                if(c[k][i]>0&&!vis[i])
                {
                    vis[i]=true;
                    pre[i]=k;
                    que[tail++]=i;
                }
            }
        }
        if(k!=t)
            break;
        int cc=Inf;
        j=t;
        i=pre[j];
        while(j!=s)
        {
            if(c[i][j]<cc)
                cc=c[i][j];
            j=i;
            i=pre[j];
        }
        flow+=cc;
        j=t;
        i=pre[j];
        while(j!=s)
        {
            f[i][j]+=cc;
            f[j][i]=-f[i][j];
            c[i][j]=G[i][j]-f[i][j];
            c[j][i]=G[j][i]-f[j][i];
            j=i;
            i=pre[j];
        }
    }
    return flow;
}
int main()
{
}
