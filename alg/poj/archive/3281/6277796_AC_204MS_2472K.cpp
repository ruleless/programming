#include<iostream>
#include<queue>
#define inf 10000000
#define Max_N 450
using namespace std;

int  s,t,n,G[Max_N][Max_N],flow[Max_N][Max_N],R[Max_N][Max_N],prev[Max_N];
bool visit[Max_N];

bool bfs()
{
	memset(visit,false,sizeof(visit));
	queue<int>que;
	visit[s]=true;
	que.push(s);
	while(!que.empty())
	{
		int tmp=que.front();
		que.pop();
		for(int i=1;i<=n;i++)
		{
			if(!visit[i]&&R[tmp][i]>0)
			{
				visit[i]=true;
				prev[i]=tmp;
				que.push(i);
				if(i==t)
				{
					while(!que.empty())
					{
						que.pop();
					}
					return true;
				}
			}
		}
	}
	return false;
}

int max_f()
{
	memset(flow,0,sizeof(flow));
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			R[i][j]=G[i][j];
	while(bfs())
	{
		int d=inf;
		j=t;
		i=prev[j];
		while(j!=s)
		{
			if(R[i][j]<d)
				d=R[i][j];
			j=i;
			i=prev[j];
		}
		j=t;
		i=prev[j];
		while(j!=s)
		{
			flow[i][j]+=d;
			flow[j][i]=-flow[i][j];
			R[i][j]=G[i][j]-flow[i][j];
			R[j][i]=G[j][i]-flow[j][i];
			j=i;
			i=prev[j];
		}
	}
	j=0;
	for(i=1;i<=n;i++)
		j+=flow[s][i];
	return j;
}

int main()
{
//	freopen("in.txt","r",stdin);
	memset(G,0,sizeof(G));
	int F,D,N,i,j,a,b,tmp;
	scanf("%d%d%d",&N,&F,&D);
	n=2+F+2*N+D;
	for(i=2;i<=F+1;i++)
		G[1][i]=1;
	a=2+F+2*N;
	b=1+F+2*N+D;
	j=2+F+2*N+D;
	for(i=a;i<=b;i++)
		G[i][j]=1;
	for(i=1;i<=N;i++)
	{
		G[1+F+i][1+F+N+i]=1;
	}
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&a,&b);
		while(a--)
		{	
			scanf("%d",&tmp);
			G[1+tmp][1+i+F]=1;
		}
		while(b--)
		{
			scanf("%d",&tmp);
			G[1+F+N+i][1+F+2*N+tmp]=1;
		}
	}
	s=1;t=2+F+2*N+D;
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",G[i][j]);
		printf("\n");
	}*/
	printf("%d\n",max_f());
	return 0;
}