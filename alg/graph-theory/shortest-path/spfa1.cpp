/*
spfa求最短路，图用静态邻接表表示 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999
struct Edge
{
    int to,w,next;
}e[1000000];

int ec,pp[N],n,dist[N],que[N*N];
bool inque[N];

void spfa(int s)
{
    int i,j,k,head=0,tail=0;
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    memset(inque,0,sizeof(inque));
    dist[s]=0;
    que[tail++]=s;
    inque[s]=true;
    while(head<tail)
    {
        k=que[head++];
        inque[k]=false;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(dist[k]+e[i].w<dist[e[i].to])
            {
                dist[e[i].to]=dist[k]+e[i].w;
                if(!inque[e[i].to])
                {
                    que[tail++]=e[i].to;
                    inque[e[i].to]=true;
                }
            }
    }
}
int main()
{
}
