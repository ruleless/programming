#include<iostream>
#include<cmath>
#include<queue>
#define Inf 9999999

using namespace std;

struct node
{
	int u,d;
	bool operator<(const struct node a)const
	{
		return d>a.d;
	}
}temp,t;

priority_queue<struct node>que;

int edge[1002][1002];
int dist[1002];
bool flag[1002];
int T,N;

int dijk()
{
	memset(flag,0,sizeof(flag));
	int i;
	for(i=1;i<=N;i++)
		dist[i]=Inf;
	dist[N]=0;
	temp.u=N;
	temp.d=0;
	que.push(temp);
	flag[N]=true;
	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		if(temp.u==1)
			return dist[1];
		flag[temp.u]=true;
		for(i=1;i<=N;i++)
		{
			if(!flag[i])
			{
				if(dist[temp.u]+edge[temp.u][i]<dist[i])
					dist[i]=dist[temp.u]+edge[temp.u][i];
				t.u=i;
				t.d=dist[i];
				que.push(t);
			}
		}
	}
	return -1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,b,c;
	scanf("%d%d",&T,&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			edge[i][j]=Inf;
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		edge[a][b]=c;
		edge[b][a]=c;
	}
	printf("%d\n",dijk());
	return 0;
}