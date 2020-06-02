#include<iostream>
#include<queue>
#define N 202
#define inf 10000000
using namespace std;

int s,t,n,G[N][N],flow[N][N],prev[N],R[N][N];
bool visit[N];

bool pfs()
{
	memset(visit,false,sizeof(visit));
	visit[s]=true;
	queue<int> que;
	que.push(s);
	while(!que.empty())
	{
		int tmp=que.front();
		que.pop();
		for(int i=1;i<=n;i++)
		{
			if(!visit[i]&&R[tmp][i]>0)
			{
				prev[i]=tmp;
				visit[i]=true;
				que.push(i);
				if(i==t)
				{
					while(!que.empty())
						que.pop();
					return true;
				}
			}
		}
	}
	return false;
}

int Max_f()
{
	memset(flow,0,sizeof(flow));
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			R[i][j]=G[i][j];
	while(pfs())
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
	int m,a,b,c;
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(G,0,sizeof(G));
		s=1;
		t=n;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			G[a][b]+=c;
		}
		printf("%d\n",Max_f());
	}
	return 0;
}