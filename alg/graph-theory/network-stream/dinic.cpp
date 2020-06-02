/*
dinic求最大流，图用静态邻接表表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Min(a,b) a<b?a:b
#define N 10000
#define Inf 9999999
struct Edge
{
    int to,cap,opt,next;
}e[100000];
int ec,pp[N],n,s,t;
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
        for(i=pp[k];i!=-1;i=e[i].next)
            if(e[i].cap>0&&level[e[i].to]==-1)
            {
                level[e[i].to]=level[k]+1;
                que[tail++]=e[i].to;
            }
    }
    return level[t]!=-1;
}

int findpath(int u,int alpha)
{
    if(u==t)
        return alpha;
    int i,j,k,w=0;
    for(i=pp[u];i!=-1;i=e[i].next)
        if(e[i].cap>0&&level[e[i].to]==level[u]+1)
            if(k=findpath(e[i].to,Min(e[i].cap,alpha-w)))
            {
                e[i].cap-=k;
                e[e[i].opt].cap+=k;
                w+=k;//多路增广 
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
