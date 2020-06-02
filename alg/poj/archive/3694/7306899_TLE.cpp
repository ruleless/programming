#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

struct Edge
{
	int to,next;
}e[600006];

int pp[100006],ec,n,cnt;

int dfn[100006],low[100006],index;

struct E
{
	int from,to;
}temp[600006];

set<int> Set;

bool is(int u,int v)
{
	int i,j,k;
	for(i=0;i<cnt;i++)
	{
		if(temp[i].from==u&&temp[i].to==v)
		{
			return true;
		}
	}
	return false;
}

void tarjan(int u,int p)
{
	int i,j,k=0,v;
	dfn[u]=low[u]=++index;
	for(i=pp[u];i!=-1;i=e[i].next)
	{
		v=e[i].to;
		if(v!=p&&dfn[v]<dfn[u])
		{
			if(!dfn[v])
			{
				tarjan(v,u);
				if(low[v]<low[u])
				{
					low[u]=low[v];
				}
				if(dfn[u]<low[v])
				{					
					temp[cnt].from=( (u<v)?u:v );
					temp[cnt++].to=( (u>v)?u:v );
				}
			}
			else if(dfn[v]<low[u])
			{
				low[u]=dfn[v];
			}
		}
	}
}

bool has(int u,int v)
{
	int i,j,k;
	for(i=pp[u];i!=-1;i=e[i].next)
	{
		if(e[i].to==v)
		{
			int x=( (u<v)?u:v );
			int y=( (u>=v)?u:v );
			Set.insert( (x-1)*n+y );
			return true;
		}
	}
	return false;
}

void solve()
{
	int i,j,k,u,v;
	for(i=0;i<cnt;i++)
	{
		u=temp[i].from;
		v=temp[i].to;
		if( Set.find( (u-1)*n+v )!=Set.end() )
		{
			cnt--;
		}
	}
	printf("%d\n",cnt);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,q,cse=0,m,l;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0) )
	{
		Set.clear();
		memset(pp,-1,sizeof(pp));
		cse++;
		ec=0;
		while(m--)
		{
			scanf("%d%d",&i,&j);
			if(!has(i,j))
			{
				e[ec].to=j;
				e[ec].next=pp[i];
				pp[i]=ec++;
				e[ec].to=i;
				e[ec].next=pp[j];
				pp[j]=ec++;
			}
		}
		scanf("%d",&q);
		printf("Case %d:\n",cse);
		memset(dfn,0,sizeof(dfn));
		index=0;
		cnt=0;
		tarjan(1,0);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			if(!has(i,j))
			{
				e[ec].to=j;
				e[ec].next=pp[i];
				pp[i]=ec++;
				e[ec].to=i;
				e[ec].next=pp[j];
				pp[j]=ec++;

				memset(dfn,0,sizeof(dfn));
				index=0;
				cnt=0;
				tarjan(1,0);
			}
			solve();
		}
		printf("\n");
	}
	return 0;
}