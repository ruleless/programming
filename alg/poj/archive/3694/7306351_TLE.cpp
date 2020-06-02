#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
	int to,next,w;
}e[600006];

int pp[100006],ec,n,cnt;

int dfn[100006],low[100006],index;

struct E
{
	int from,to;
}temp[600006];

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
					temp[cnt].from=u;
					temp[cnt++].to=v;
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
			e[i].w++;
			return true;
		}
	}
	return false;
}

void solve()
{
	int i,j,k,u,v;
	memset(dfn,0,sizeof(dfn));
	index=0;
	cnt=0;
	tarjan(1,0);
	for(i=0;i<cnt;i++)
	{
		u=temp[i].from;
		v=temp[i].to;
		for(j=pp[u];j!=-1;j=e[j].next)
		{
			if(e[j].to==v)
			{
				if(e[j].w>1)
				{
					cnt--;
				}
				break;
			}
		}
	}
	printf("%d\n",cnt);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,q,cse=0,m;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0) )
	{
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
				e[ec].w=1;
				pp[i]=ec++;
				e[ec].to=i;
				e[ec].w=1;
				e[ec].next=pp[j];
				pp[j]=ec++;
			}
		}
		scanf("%d",&q);
		printf("Case %d:\n",cse);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			if(!has(i,j))
			{
				e[ec].to=j;
				e[ec].next=pp[i];
				e[ec].w=1;
				pp[i]=ec++;
				e[ec].to=i;
				e[ec].w=1;
				e[ec].next=pp[j];
				pp[j]=ec++;
			}
			solve();
			
		}
		printf("\n");
	}
	return 0;
}