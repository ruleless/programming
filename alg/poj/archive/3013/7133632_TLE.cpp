#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
	int v,w;
	struct Edge* next;
}edge[50006];
int n;
int dist[50006],visited[50006];
struct Node
{
	int u,d;
	bool operator<(const struct Node a)const
	{
		return d>a.d;
	}
}t1,t2;
priority_queue<struct Node>que;
#define MAX 1<<20
int ans;

void dijk()
{
	struct Edge*p;
	int i,j,k;
	memset(visited,0,sizeof(visited));
	for(i=2;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	t1.u=1;
	t1.d=0;
	que.push(t1);
	while(!que.empty())
	{
		t1=que.top();
		que.pop();
		visited[t1.u]=1;
		for(p=edge[t1.u].next;p!=NULL;p=p->next)
		{
			if(!visited[p->v]&&(dist[t1.u]+p->w)<dist[p->v])
			{
				dist[p->v]=dist[t1.u]+p->w;
				t2.u=p->v;
				t2.d=dist[p->v];
				que.push(t2);
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		if(dist[i]>=MAX)
		{
			ans=-1;
			break;
		}
		else 
		{
			ans+=dist[i]*edge[i].w;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	struct Edge*p,*q;
	int i,j,k,l,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&edge[i].w);
			edge[i].next=NULL;
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			p=&edge[i];
			while(p->next!=NULL)
			{
				p=p->next;
			}
			q=new struct Edge;
			q->next=NULL;
			q->v=j;
			q->w=k;
			p->next=q;

			p=&edge[j];
			while(p->next!=NULL)
			{
				p=p->next;
			}
			q=new struct Edge;
			q->next=NULL;
			q->v=i;
			q->w=k;
			p->next=q;
		}
		ans=0;
		dijk();
		if(ans==-1)
		{
			printf("No Answer\n");
		}
		else
			printf("%d\n",ans);
	}
	return 0;
}