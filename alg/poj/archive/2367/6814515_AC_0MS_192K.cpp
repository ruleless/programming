#include<iostream>
#include<stack>
using namespace std;

int edge[105][105],n,deg[105];

void topsort()
{
	int i,j;
	memset(deg,0,sizeof(deg));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(edge[i][j])
				deg[j]++;
		}
	}
	stack<int> sta;
	for(i=1;i<=n;i++)
	{
		if(deg[i]==0)
		{
			sta.push(i);
		}
	}
	int cnt=0;
	while(!sta.empty())
	{
		i=sta.top();
		sta.pop();
		cnt++;
		if(cnt==n)
		{
			printf("%d\n",i);
		}
		else 
		{
			printf("%d ",i);
		}
		for(j=1;j<=n;j++)
		{
			if(edge[i][j]==1)
			{
				deg[j]--;
				if(deg[j]==0)
					sta.push(j);
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&n);
	memset(edge,0,sizeof(edge));
	for(i=1;i<=n;i++)
	{
		while(scanf("%d",&j)&&j)
		{
			edge[i][j]=1;
		}
	}
	topsort();
	return 0;
}