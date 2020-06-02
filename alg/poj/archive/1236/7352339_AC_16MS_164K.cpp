#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n;
bool edge[120][120];
int dfn[120],low[120],stack[120],top,index,cnt,deg[120],degin[120];
bool instack[120];

set<int>Set;
set<int>::iterator it;

void tarjan(int u)
{
	int i,j,k,v;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	instack[u]=true;
	for(i=0;i<n;i++)
	{
		if(edge[u][i])
		{
			if(!dfn[i])
			{
				tarjan(i);
				if(low[i]<low[u])
				{
					low[u]=low[i];
				}
			}
			else if(instack[i]&&dfn[i]<low[u])
			{
				low[u]=dfn[i];
			}
		}
	}
	if(dfn[u]==low[u])
	{
		do
		{
			j=stack[top--];
			instack[j]=false;
			Set.insert(j);
		}while(j!=u);
		for(it=Set.begin();it!=Set.end();it++)
		{
			//printf("%d ",*it);
			i=*it;
			for(j=0;j<n;j++)
			{
				if(edge[j][i]&&Set.find(j)==Set.end())
				{
					degin[cnt]++;
				}
				if(edge[i][j]&&Set.find(j)==Set.end())
				{
					deg[cnt]++;
				}
			}
		}
	//	printf("%d %d\n",cnt,deg[cnt]);
		cnt++;
		Set.clear();
	}
}

void solve()
{
	int i,j,k;
	index=top=cnt=0;
	memset(deg,0,sizeof(deg));
	memset(dfn,0,sizeof(dfn));
	memset(degin,0,sizeof(degin));
	memset(instack,0,sizeof(instack));
	for(i=0;i<n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	//printf("%d\n",cnt);
	if(cnt==1)
	{
		printf("1\n0\n");
	}
	else
	{
		j=0;k=0;
		for(i=0;i<cnt;i++)
		{
			if(degin[i]==0)
			{
				j++;
			}
			if(deg[i]==0)
			{
				k++;
			}

		}
		printf("%d\n%d\n",j,j>k?j:k);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	memset(edge,0,sizeof(edge));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		while(scanf("%d",&j)&&j)
		{
			j--;
			edge[i][j]=true;
		}
	}
	solve();
	return 0;
}