#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int n,m;
double dist[36];
struct Edge
{
	int u,v;
	double w;
}e[1000];

bool bellman(int s)
{
	int i,j,k;
	memset(dist,0,sizeof(dist));
	dist[s]=1;
	for(j=1;j<=n-1;j++)
	{
		bool flag=true;
		for(i=0;i<m;i++)
		{
			if(dist[e[i].u]*e[i].w>dist[e[i].v])
			{
				flag=false;
				dist[e[i].v]=dist[e[i].u]*e[i].w;
			}
		}
		if(flag)
		{
			if(dist[s]>1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(dist[e[i].u]*e[i].w>dist[e[i].v])
		{
			return true;
		}
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,cse=0;
	double dd;
	string s1,s2;
	while(scanf("%d",&n)!=EOF&&n)
	{
		cse++;
		map<string,int>Map;
		for(i=1;i<=n;i++)
		{
			cin>>s1;
			Map[s1]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			cin>>s1>>dd>>s2;
			e[i].u=Map[s1];
			e[i].v=Map[s2];
			e[i].w=dd;
		}
		if(bellman(1))
		{
			printf("Case %d: Yes\n",cse);
		}
		else
		{
			printf("Case %d: No\n",cse);
		}
		Map.clear();
	}
	return 0;
}