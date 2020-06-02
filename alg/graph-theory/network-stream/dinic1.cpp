/*
dinic求最大流，图用邻接矩阵表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Min(a,b) a<b?a:b
#define Inf 9999999
int G[N][N],c[N][N],n,s,t;
int level[N],que[N];

bool makelevel()
{
    int i,j,k,head=0,tail=0;
    memset(level,-1,sizeof(level));
    level[s]=0;
    que[tail++]=s;
    while(head<tail)
    {
        k=que[head++];
        for(i=1;i<=n;i++)
            if(c[k][i]>0&&level[i]==-1)
            {
                level[i]=level[k]+1;
                que[tail++]=i;
            }
    }
    return level[t]!=-1;
}

int findpath(int u,int alpha)
{
    if(u==t)
        return alpha;
    int i,j,k,w;
    w=0;
    for(i=1;i<=n;i++)
    {
        if(c[u][i]>0&&level[i]==level[u]+1)
        {
            if(k=findpath(i,Min(c[u][i],alpha-w)))
            {
                c[u][i]-=k;
                c[i][u]+=k;
                w+=k;
            }
        }
    }
    return w;
}

int dinic()
{
    int i,j,k=0;
    while(makelevel())
        while(i=findpath(s,Inf))
            k+=i;
    return k;
}

int main()
{
}
