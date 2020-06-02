#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool edge[1020][1020];
int n;
int from[1000005],to[1000005],top;
int dfn[1020],low[1020],index,cnt;
set<int>Set[1020];
set<int>::iterator it;
bool inG[1024];
int color[1024];
bool vis[1024];
set<int>S[1020];//联通分量
set<int>::iterator iter;
int cc;

void tarjan(int u,int p)
{
	int i,j,k,v;
	dfn[u]=low[u]=++index;
	for(i=1;i<=n;i++)
	{
		if(edge[u][i])
		{
			v=i;
			if(v!=p&&dfn[v]<dfn[u])
			{
				from[++top]=u;
				to[top]=v;
				if(!dfn[v])
				{
					tarjan(v,u);
					if(low[v]<low[u])
					{
						low[u]=low[v];
					}
					if(dfn[u]<=low[v])
					{
						do
						{
							i=from[top];
							j=to[top--];
							Set[cnt].insert(i);
							Set[cnt].insert(j);
						}while( !(i==u&&j==v) );
						cnt++;
					}
				}
				else if(dfn[v]<low[u])
				{
					low[u]=dfn[v];
				}
			}
		}
	}
}

bool isBinary(int u,int col)
{
	int i,j,k;
	color[u]=col;
	for(i=1;i<=n;i++)
	{
		if(edge[u][i]&&inG[i])
		{
			if(color[i]==-1)
			{
				if(!isBinary( i,( (col)?0:1 ) ))
				{
					return false;
				}
			}
			else if(color[i]==color[u] )
			{
				return false;
			}
		}
	}
	return true;
}

void solve(int tt)
{
	int i,j,k;
	memset(dfn,0,sizeof(dfn));
	top=index=0;
	tarjan(tt,0);
	for(i=0;i<cnt;i++)
	{
		memset(color,-1,sizeof(color));
		memset(inG,0,sizeof(inG));
		for(it=Set[i].begin();it!=Set[i].end();it++)
		{
			j=*it;
			inG[j]=true;
		}
		if(!isBinary(j,0))
		{
		//	printf("YES\n");
			for(it=Set[i].begin();it!=Set[i].end();it++)
			{
				vis[*it]=true;
			}
		}
		/*else 
		{
			printf("NO\n");
		}*/
	}
}

bool visit[1020];
void dfs(int u)
{
	int i,j,k;
	S[cc].insert(u);
	visit[u]=true;
	for(i=1;i<=n;i++)
	{
		if(edge[u][i]&&!visit[i])
		{
			dfs(i);
		}
	}
}

void f()
{
	cc=0;
	memset(visit,0,sizeof(visit));
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			dfs(i);
			cc++;
		}
	}
	for(i=0;i<cc;i++)
	{
		if(S[i].size()>=3)
		{
			iter=S[i].begin();
			j=*iter;
			solve(j);
		}
	}
	k=0;
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			k++;
		}
	}
	printf("%d\n",k);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					edge[i][j]=false;
				}
				else
				{
					edge[i][j]=true;
				}
			}
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			edge[i][j]=false;
			edge[j][i]=false;
		}
		f();
		/*for(i=0;i<cnt;i++)
		{
			for(it=Set[i].begin();it!=Set[i].end();it++)
			{
				printf("%d ",*it);
			}
			printf("\n");
		}*/
	}
	return 0;
}