#include<iostream>
using namespace std;


int N,M;
int edge[1002][1002];
int closedge[1002];
bool flag[1002];

int prim()
{
	memset(flag,0,sizeof(flag));
	int i,j,Max,sum=0;
	flag[1]=true;
	for(i=2;i<=N;i++)
	{
		closedge[i]=edge[1][i];
	}
	for(i=1;i<=N-1;i++)
	{
		for(Max=1;flag[Max]==true;Max++);
		if(Max==N+1)
			break;
		for(j=Max+1;j<=N;j++)
			if(!flag[j])
				if(closedge[j]>closedge[Max])
					Max=j;
		if(closedge[Max]==0)
			break;
		flag[Max]=true;
		sum+=closedge[Max];
		for(j=2;j<=N;j++)
		{
			if(!flag[j])
			{
				if(edge[Max][j]>closedge[j])
					closedge[j]=edge[Max][j];
			}
		}
	}
	if(i==N)
		return sum;
	else
		return -1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,a,b,c;
	scanf("%d%d",&N,&M);
	memset(edge,0,sizeof(edge));
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c>edge[a][b])
		{
			edge[a][b]=c;
			edge[b][a]=c;
		}
	}
	printf("%d\n",prim());
	return 0;
}