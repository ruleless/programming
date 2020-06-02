#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

struct Point 
{
	double x,y;
}p[205];
#define MAX 10e20

double edge[205][205],closedge[205];
bool vis[205];
int n;

struct Node
{
	int u;
	double d;
	bool operator<(const struct Node a)const
	{
		return d>a.d;
	}
}t1,t2;
priority_queue<struct Node>que;

double prim()
{
	int i,j,k;
	while(!que.empty())
	{
		que.pop();
	}
	for(i=1;i<=n;i++)
	{
		closedge[i]=MAX;
	}
	closedge[1]=0;
	memset(vis,0,sizeof(vis));
	t1.u=1;
	t1.d=0;
	que.push(t1);
	while(!que.empty())
	{
		t1=que.top();
		que.pop();
		int u=t1.u;
		if(vis[u])
		{
			continue;
		}
		vis[u]=true;
		if(u==2)
		{
			return closedge[u];
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i]&&edge[u][i]<closedge[i])
			{
				closedge[i]=edge[u][i];
				t2.u=i;
				t2.d=closedge[i];
				que.push(t2);
			}
		}
	}
}

void solve(int cse)
{
	int i,j,k;
	printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cse,prim());
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		k++;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				edge[i][j]=sqrt( (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y) );
				edge[j][i]=edge[i][j];
			}
		}
		solve(k);
	}
	return 0;
}