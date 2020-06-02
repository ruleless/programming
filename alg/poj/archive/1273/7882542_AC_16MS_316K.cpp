#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define Inf 9999999
#define N 205

int G[N][N],c[N][N],que[N],pre[N],n;
bool vis[N];
int ek(int s,int t)
{
    int flow=0,i,j,k;
    while(true)
    {
        int head=0,tail=0;
        memset(vis,0,sizeof(vis));
        que[tail++]=s;
        vis[s]=true;
        while(head<tail)
        {
            k=que[head++];
            if(k==t)break;
            for(i=1;i<=n;i++)
            {
                if(!vis[i]&&c[k][i]>0)
                {
                    vis[i]=true;
                    que[tail++]=i;
                    pre[i]=k;
                }
            }
        }
        if(k!=t)break;
            int temp=Inf;
            j=t,i=pre[j];
            while(j!=s)
            {
                if(c[i][j]<temp)
                    temp=c[i][j];
                j=i,i=pre[j];
            }
            flow+=temp;
            j=t,i=pre[j];
            while(j!=s)
            {
                c[i][j]-=temp;
                c[j][i]+=temp;
                j=i,i=pre[j];
            }
    }
    return flow;
}

int main()
{
   // freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            c[i][j]+=k;
        }
        printf("%d\n",ek(1,n));
    }
    //while(1);
    return 0;
}
