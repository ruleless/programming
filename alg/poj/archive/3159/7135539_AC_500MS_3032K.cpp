#include <iostream>

using namespace std;

int dist[30006],stack[300006],instack[300006],n;

struct Edge
{
	int to,w;
	int next;
}edge[150006];
int pre[30006];
int ec;

const int MAX=0x7fffffff;

int spfa()
{
	int i,j,k,head,tail,top;
	head=tail=0;
	top=0;
	memset(instack,0,sizeof(instack));
	for(i=2;i<=n;i++)
	{
		dist[i]=MAX;
	}
	dist[1]=0;
	stack[++top]=1;
	instack[1]=1;
	while(top!=0)
	{
		k=stack[top--];
		instack[k]=0;
		for(i=pre[k];i!=-1;i=edge[i].next)
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
	return dist[n];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	scanf("%d%d",&n,&m);
	memset(pre,-1,sizeof(pre));
	ec=0;
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		edge[ec].to=j;
		edge[ec].w=k;
		edge[ec].next=pre[i];
		pre[i]=ec++;
	}
	printf("%d\n",spfa());
	return 0;
}