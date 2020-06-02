#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool edge[1020][1020];
int n;
int from[2000005],to[2000005],top;
int dfn[1020],low[1020],index,cnt;
set<int>Set;
set<int>::iterator it;
bool inG[1024];
int color[1024];
bool vis[1024];
set<int>S[1020];//联通分量
set<int>::iterator iter;
int cc;

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

void tarjan(int u,int p)
{
	int i,j,k,v,x,y;
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
						memset(inG,0,sizeof(inG));
						do
						{
							x=from[top];
							y=to[top--];
							inG[x]=inG[y]=true;
							Set.insert(x);
							Set.insert(y);
						}while( !( (x==u&&y==v) ) );
						memset(color,-1,sizeof(color));
						
						if(!isBinary(u,0))
						{
							for(it=Set.begin();it!=Set.end();it++)
							{
								vis[*it]=true;
							}
						}
						Set.clear();
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


void solve()
{
	int i,j,k;
	memset(dfn,0,sizeof(dfn));
	top=index=0;
	for(i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i,0);
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
		solve();
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
