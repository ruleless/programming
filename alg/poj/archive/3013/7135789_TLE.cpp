#include <iostream>
using namespace std;

struct Edge
{
	int to,w;
	int next;
}edge[100006];
int p[50006],ec,pp[50006];
int n;
__int64 dist[50006];
int instack[50006];
int stack[50006];
const __int64 MAX = 0x7fffffffffffffff;
__int64 ans;

void spfa()
{
	int i,j,k,head,tail;
	for(i=2;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	head=tail=0;
	int top=0;
	stack[++top]=1;
	memset(instack,0,sizeof(instack));
	instack[1]=1;
	while(top)
	{
		k=stack[top--];
		instack[k]=0;
		for(i=p[k];i!=-1;i=edge[i].next)
		{
			if(dist[k]+edge[i].w<dist[edge[i].to])
			{
				dist[edge[i].to]=dist[k]+edge[i].w;
				if(!instack[edge[i].to])
				{
					stack[++top]=edge[i].to;
					instack[edge[i].to]=1;
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
			ans+=__int64(dist[i]*pp[i]);
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,l,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(p,-1,sizeof(p));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pp[i]);
		}
		ec=0;
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);		
			if(i!=j)
			{
				edge[ec].to=j;
				edge[ec].w=k;
				edge[ec].next=p[i];
				p[i]=ec++;
				edge[ec].to=i;
				edge[ec].w=k;
				edge[ec].next=p[j];
				p[j]=ec++;
			}
		}
		ans=0;
		spfa();
	//	printf("Yes\n");
		if(ans==-1)
		{
			printf("No Answer\n");
		}
		else
			printf("%I64d\n",ans);
	}
	return 0;
}