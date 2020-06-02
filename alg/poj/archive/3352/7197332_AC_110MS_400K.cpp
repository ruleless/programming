#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

struct Edge
{
	int to,flag,next;
}e[10006];

set<int>Set;
set<int>::iterator it;

int pp[5006],ec,n,dfn[5006],low[5006],index,deg[5000];
int parent[5006];

int Find(int x)
{
	if(parent[x]<0)
	{
		return x;
	}
	int r=Find(parent[x]);
	parent[x]=r;
	return r;
}

void Union(int x,int y)
{
	int a=Find(x);
	int b=Find(y);
	parent[b]=a;
}

void tarjan(int u,int p)
{
	int i,j,k,v;
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
					for(j=pp[u];j!=-1;j=e[j].next)
					{
						if(e[j].to==v)
						{
							e[j].flag=0;
							break;
						}
					}
					for(j=pp[v];j!=-1;j=e[j].next)
					{
						if(e[j].to==u)
						{
							e[j].flag=0;
							break;
						}
					}
					Set.insert(u);
					Set.insert(v);
				}
			}
			else if(dfn[v]<low[u])
			{
				low[u]=dfn[v];
			}
		}
	}
}

bool vis[5006];

void dfs(int u)
{
	//printf("Yes\n");
	int i;
	for(i=pp[u];i!=-1;i=e[i].next)
	{
		int v=e[i].to;
		if(e[i].flag&&!vis[v])
		{
			Union(u,v);
			vis[v]=true;
			dfs(v);
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,m;
	scanf("%d%d",&n,&m);
	memset(pp,-1,sizeof(pp));
	ec=0;
	while(m--)
	{
		scanf("%d%d",&i,&j);
		for(k=pp[i];k!=-1;k=e[k].next)
		{
			if(j==e[k].to)
			{
				break;
			}
		}
		if(k==-1)
		{
			e[ec].to=j;
			e[ec].flag=1;
			e[ec].next=pp[i];
			pp[i]=ec++;
			e[ec].to=i;
			e[ec].flag=1;
			e[ec].next=pp[j];
			pp[j]=ec++;
		}
	}

	memset(dfn,0,sizeof(dfn));
	index=0;
	tarjan(1,0);

	memset(deg,0,sizeof(deg));
	memset(parent,-1,sizeof(parent));
	set<int>ss;
	for(it=Set.begin();it!=Set.end();it++)
	{
		k=*it;
		memset(vis,0,sizeof(vis));
		vis[k]=true;
		if(Find(k)==k)
		{
			ss.insert(k);
			dfs(k);
		}
	}
	for(it=Set.begin();it!=Set.end();it++)
	{
		k=*it;
		//printf("%d\n",k);
		int l=Find(k);
		for(i=pp[k];i!=-1;i=e[i].next)
		{
			j=e[i].to;
			if(Find(j)!=l)
			{
				deg[l]++;
			}
		}
	}
	int leaf=0;
	for(it=ss.begin();it!=ss.end();it++)
	{
		k=*it;
		if(deg[k]==1)
		{
			leaf++;
		}
	}
	int ans;
	
		ans=(1+leaf)/2;
	printf("%d\n",ans);

	/*for(i=1;i<=n;i++)
	{
		for(k=pp[i];k!=-1;k=e[k].next)
		{
			printf("%d ",e[k].to);
		}
		printf("\n");
	}*/
	return 0;
}
