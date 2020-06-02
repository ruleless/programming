#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
#define MAXN 206

int visited[MAXN],f[MAXN][MAXN],c[MAXN][MAXN],n,pre[MAXN];

int ek(int s,int t)
{
    int i,j,k,flow=0;
    queue<int>que;
    memset(f,0,sizeof(f));
    while(1)
    {
        while(!que.empty())
        {
            que.pop();
        }
        memset(visited,0,sizeof(visited));
        que.push(s);
        k=0;
        visited[s]=1;
        while(!que.empty())
        {
            k=que.front();
            que.pop();
            if(k==t)
            {
                break;
            }
            for(i=1;i<=n;i++)
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
        i=t;
        j=pre[i];
        int min1=1<<30;
        while(i!=s)
        {
            if(c[j][i]<min1)
            {
                min1=c[j][i];
            }
            i=j;
            j=pre[i];
        }
        flow+=min1;
        i=t;
        j=pre[i];
        while(i!=s)
        {
            f[j][i]+=min1;
            f[i][j]=-f[j][i];
            c[j][i]-=f[j][i];
            c[i][j]-=f[i][j];
            i=j;
            j=pre[i];
        }
    }
    return flow;
}

int main()
{
    //freopen("in.txt","r",stdin);
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
    //system("PAUSE");
    return EXIT_SUCCESS;
}
