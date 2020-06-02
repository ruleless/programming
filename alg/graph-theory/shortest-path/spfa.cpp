/*
spfa求最短路,邻接矩阵保存图 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999

int edge[N][N],n,dist[N],que[N];
bool inque[N];

void spfa(int s)
{
    int i,j,k,head=0,tail=0;
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    memset(inque,0,sizeof(inque));
    que[tail++]=s;
    inque[s]=true;
    while(head<tail)
    {
        k=que[head++];
        inque[k]=false;
        for(i=1;i<=n;i++)
            if(dist[k]+edge[k][i]<dist[i])
            {
                dist[i]=dist[k]+edge[k][i];
                if(!inque[i])
                {
                    que[tail++]=i;
                    inque[i]=true;
                }
            }
    }
}

int main()
{
}
