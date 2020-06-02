#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
    int to,w,next;
}edge[100006];
int p[50006],ec;
int pp[50006],n;

const __int64 MAX=0x7fffffffffffffff;

struct Node
{
    int u,d;
    bool operator<(const struct Node a)const
    {
        return d>a.d;
    }
}t1,t2;

__int64 dist[50006],ans;
int visited[50006];

priority_queue<struct Node>que;

void dij()
{
    int i,j,k;
    for(i=2;i<=n;i++)
    {
        dist[i]=MAX;
    }
    dist[1]=0;
    t1.u=1;
    t1.d=0;
	while(!que.empty())
	{
		que.pop();
	}
    que.push(t1);
    memset(visited,0,sizeof(visited));
	int ctr=0;
    while(!que.empty())
    {
        t1=que.top();
        que.pop();
        k=t1.u;
        visited[k]=1;
		ctr++;
		if(ctr==n)
		{
			break;
		}
        for(i=p[k];i!=-1;i=edge[i].next)
        {
            if(!visited[edge[i].to]&&dist[k]+edge[i].w<dist[edge[i].to])
            {
                dist[edge[i].to]=dist[k]+edge[i].w;
                t2.d=dist[edge[i].to];
                t2.u=edge[i].to;
                que.push(t2);
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(dist[i]>=MAX)
        {
            ans=-1;
			break;
        }
        else 
        {
            ans+=dist[i]*pp[i];
        }
    }
}

int main(int argc, char *argv[])
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,t,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&pp[i]);
        }
        memset(p,-1,sizeof(p));
        ec=0;
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            edge[ec].to=j;
            edge[ec].w=k;
            edge[ec].next=p[i];
            p[i]=ec++;
            edge[ec].to=i;
            edge[ec].w=k;
            edge[ec].next=p[j];
            p[j]=ec++;
        }
        ans=0;
        dij();
		if(ans==-1)
		{
			printf("No Answer\n");
		}
		else
		{
			printf("%I64d\n",ans);
		}
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
