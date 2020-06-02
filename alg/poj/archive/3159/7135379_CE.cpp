#include <iostream>

using namespace std;

int dist[30006],que[30006],inque[30006],n;

struct Edge
{
	int u,w;
	struct Edge* next;
}edge[30006];
struct Edge* e[30006];

const MAX=0x7fffffff;

int spfa()
{
	struct Edge*p;
	int i,j,k,head,tail;
	head=tail=0;
	memset(inque,0,sizeof(inque));
	for(i=2;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	que[tail++]=1;
	inque[1]=1;
	while(head<tail)
	{
		k=que[head++];
		inque[k]=0;
		for(p=edge[k].next;p!=NULL;p=p->next)
		{
			if(dist[k]+p->w<dist[p->u])
			{
				dist[p->u]=dist[k]+p->w;
				if(!inque[p->u])
				{
					que[tail++]=p->u;
					inque[p->u]=1;
				}
			}
		}
	}
	return dist[n];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	struct Edge*p,*q;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		edge[i].next=NULL;
		e[i]=&edge[i];
	}
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		q=new struct Edge;
		q->next=NULL;
		q->u=j;
		q->w=k;
		e[i]->next=q;
		e[i]=e[i]->next;
	}
	printf("%d\n",spfa());
	return 0;
}