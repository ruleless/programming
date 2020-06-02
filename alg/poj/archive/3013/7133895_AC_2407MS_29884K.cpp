#include <iostream>
using namespace std;

struct Edge
{
	__int64 v,w;
	struct Edge* next;
}edge[50006];
struct Edge*e[50006];
__int64 n;
__int64 dist[50006];
__int64 inqueue[50006];
__int64 q[50006];
const __int64 MAX = 0x7fffffffffffffff;
__int64 ans;

void spfa()
{
	struct Edge* p;
	__int64 i,j,k,head,tail;
	for(i=2;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	head=tail=0;
	q[tail++]=1;
	memset(inqueue,0,sizeof(inqueue));
	inqueue[1]=1;
	while(head<tail)
	{
		k=q[head++];
		inqueue[k]=0;
		for(p=edge[k].next;p!=NULL;p=p->next)
		{
			if(dist[k]+p->w<dist[p->v])
			{
				dist[p->v]=dist[k]+p->w;
				if(!inqueue[p->v])
				{
					q[tail++]=p->v;
					inqueue[p->v]=1;
				}
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
	__int64 i,j,k,l,m,t;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%I64d",&edge[i].w);
			edge[i].next=NULL;
			e[i]=&edge[i];
		}
		while(m--)
		{
			scanf("%I64d%I64d%I64d",&i,&j,&k);
			if(i!=j)
			{
			q=new struct Edge;
			q->next=NULL;
			q->v=j;
			q->w=k;
			e[i]->next=q;
			e[i]=e[i]->next;

			q=new struct Edge;
			q->next=NULL;
			q->v=i;
			q->w=k;
			e[j]->next=q;
			e[j]=e[j]->next;
			}
		}
		ans=0;
		spfa();
		if(ans==-1)
		{
			printf("No Answer\n");
		}
		else
			printf("%I64d\n",ans);
	}
	
	return 0;
}