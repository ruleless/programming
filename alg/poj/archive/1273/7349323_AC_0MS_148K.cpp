#include <iostream>
#include <cstdio>

using namespace std;

#define Min(a,b) a<b?a:b

struct Edge
{
	int to;
	int cap;
	int next;
	int opt;
}e[40006];

int pp[205],ec,n;
int level[205],que[205],s,t;

bool makelevel()
{
	int i,j,k;
	memset(level,-1,sizeof(level));
	int head=0,tail=0;
	level[s]=0;
	que[tail++]=s;
	while(head<tail)
	{
		k=que[head++];
		for(i=pp[k];i!=-1;i=e[i].next)
		{
			if(e[i].cap>0&&level[e[i].to]==-1)
			{
				level[e[i].to]=level[k]+1;
				que[tail++]=e[i].to;
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
	for(i=pp[u];i!=-1;i=e[i].next)
	{
		if(e[i].cap>0&&level[u]+1==level[e[i].to])
		{
			if(k=findpath(e[i].to,Min(e[i].cap,alpha-w)))
			{
				e[i].cap-=k;
				e[e[i].opt].cap+=k;
				w+=k;
			}
		}
	}
	if(w==0)
	{
		level[u]=-1;
	}
	return w;
}

int dinic()
{
	int i,j,k=0;
	while(makelevel())
	{
		while(i=findpath(s,99999999))
		{
			k+=i;
		}
	}
	return k;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		s=1;
		t=n;
		memset(pp,-1,sizeof(pp));
		ec=0;
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			e[ec].to=j;
			e[ec].cap=k;
			e[ec].next=pp[i];
			e[ec].opt=ec+1;
			pp[i]=ec++;

			e[ec].to=i;
			e[ec].cap=0;
			e[ec].next=pp[j];
			e[ec].opt=ec-1;
			pp[j]=ec++;
		}
		printf("%d\n",dinic());
	}
	return 0;
}