/*
最小费用路算法求最小费用最大流
其中增广路径用spfa算法求得 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
#define Inf 9999999
int G[N][N],c[N][N],ft[N][N],f[N][N],n;//ft[i][j]用来保存从i到j的费用
int que[N],dist[N],pre[N];
bool inque[N];

int mcmf(int s,int t)
{
    int i,j,k,head,tail,res=0;
    memset(f,0,sizeof(f));
    while(true)
    {
        head=tail=0;
        for(i=1;i<=n;i++)
            dist[i]=Inf;
        memset(inque,0,sizeof(inque));
        memset(pre,-1,sizeof(pre));
        dist[s]=0;
        inque[s]=true;
        que[tail++]=s;
        while(head<tail)
        {
            k=que[head++];
            inque[k]=false;
            for(i=1;i<=n;i++)
            {
                if(c[k][i]>0&&dist[k]+ft[k][i]<dist[i])
                {
                    dist[i]=dist[k]+ft[k][i];
                    pre[i]=k;
                    if(!inque[i])
                    {
                        que[tail++]=i;
                        inque[i]=true;
                    }
                }
            }
        }
        if(pre[t]==-1)
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
        j=t;
        i=pre[j];
        while(j!=s)
        {
            res+=ft[i][j]*cc;
            f[i][j]+=cc;
            f[j][i]=-f[i][j];
            c[i][j]=G[i][j]-f[i][j];
            c[j][i]=G[j][i]-f[j][i];
            j=i;
            i=pre[j];
        }
    }
    return res;
}
int main()
{
}
