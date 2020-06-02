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
}e[1000000];

int pp[20006],ec,n;
int level[20006],que[20006],s,t;

bool makelevel()
{
	int i,j,k;
	int head=0,tail=0;
	memset(level,-1,sizeof(level));
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
	int i,j,k;
	if(u==t)
	{
		return alpha;
	}
	int w=0;
	for(i=pp[u];i!=-1;i=e[i].next)
	{
		if(e[i].cap>0&&level[u]+1==level[e[i].to])
		{
			if(k=findpath( e[i].to,Min(e[i].cap,alpha-w) ) )
			{
				e[i].cap-=k;
				if(e[i].opt!=-1)e[e[i].opt].cap+=k;
				w+=k;
			}
		}
	}
	if(!w)
	{
		//level[u]=-1;
	}
	return w;
}

int dinic()
{
	int i,j,k=0;
	while(makelevel())
	{
		if(i=findpath(s,90000000))
		{
			k+=i;
		}
	}
	return k;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,m;
	scanf("%d%d",&n,&m);
	memset(pp,-1,sizeof(pp));
	ec=0;
	for(k=1;k<=n;k++)
	{
		scanf("%d%d",&i,&j);
		e[ec].to=k;
		e[ec].cap=i;
		e[ec].opt=-1;
		e[ec].next=pp[0];
		pp[0]=ec++;

		e[ec].to=n+1;
		e[ec].cap=j;
		e[ec].opt=-1;
		e[ec].next=pp[k];
		pp[k]=ec++;
	}
	s=0,t=n+1;
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		e[ec].to=j;
		e[ec].cap=k;
		e[ec].opt=ec+1;
		e[ec].next=pp[i];
		pp[i]=ec++;

		e[ec].to=i;
		e[ec].cap=k;
		e[ec].opt=ec-1;
		e[ec].next=pp[j];
		pp[j]=ec++;
	}
	/*for(i=0;i<=n+1;i++)
	{
		printf("%d: ",i);
		for(j=pp[i];j!=-1;j=e[j].next)
		{
			printf("%d(%d) ",e[j].to,e[j].cap);
		}
		printf("\n");
	}*/
	printf("%d\n",dinic());
	//while(1);
	return 0;
}
