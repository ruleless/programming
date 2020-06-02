#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
	int to,next;
}e[500006];

int pp[100006],ec,n;

int dfn[100006],low[100006],index;

int tarjan(int u,int p)
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
					k++;
				}
			}
			else if(dfn[v]<low[u])
			{
				low[u]=dfn[v];
			}
		}
	}
	return k;
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
			e[ec].to=j;
			e[ec].next=pp[i];
			pp[i]=ec++;
			e[ec].to=i;
			e[ec].next=pp[j];
			pp[j]=ec++;
		}
		scanf("%d",&q);
		printf("Case %d:\n",cse);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			e[ec].to=j;
			e[ec].next=pp[i];
			pp[i]=ec++;
			e[ec].to=i;
			e[ec].next=pp[j];
			pp[j]=ec++;
			memset(dfn,0,sizeof(dfn));
			index=0;
			printf("%d\n",tarjan(1,0));
		}
		printf("\n");
	}
	return 0;
}