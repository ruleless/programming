#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 99999999

#define Min(a,b) a<b?a:b

int G[1005][1005],c[1005][1005],level[1005],que[1005],head,tail,s,t,n;

bool makelevel()
{
	int i,j,k;
	memset(level,-1,sizeof(level));
	head=tail=0;
	level[s]=0;
	que[tail++]=s;
	while(head<tail)
	{
		k=que[head++];
		for(i=1;i<=n;i++)
		{
			if(c[k][i]>0&&level[i]==-1)
			{
				level[i]=level[k]+1;
				que[tail++]=i;
			}
		}
	}
	return level[t]!=-1;
}

int findpath(int u,int alpha)
{
	int i,j,k,w;
	if(u==t)
	{
		return alpha;
	}
	w=0;
	for(i=1;i<=n;i++)
	{
		if(c[u][i]>0&&level[u]+1==level[i])
		{
			if(k=findpath(i,Min(c[u][i],alpha-w) )) 
			{
				w+=k;
				c[u][i]-=k;
				c[i][u]+=k;
			}
		}
	}
	if(!w)
	{
		level[u]=-1;
	}
	return w;
}

int dinic()
{
	int i,j=0,k=0;
	while(makelevel())
	{
		while(k=findpath(s,MAX))
		{
			j+=k;
		}
	}
	return j;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(G,0,sizeof(G));
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			i++;
			j++;
			G[i][j]=k;
			G[j][i]=k;
		}
		int res=1<<30;
		s=n;
		for(i=1;i<n;i++)
		{
			memcpy(c,G,sizeof(G));
			t=i;
			j=dinic();
			if(j<res)
			{
				res=j;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}