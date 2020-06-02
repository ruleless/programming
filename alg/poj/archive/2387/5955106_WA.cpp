#include<iostream>
#include<cmath>
#define Inf 9999999

using namespace std;

int edge[1001][1001];
int dist[1002];
bool flag[1002];
int T,N;

int dijk()
{
	memset(flag,0,sizeof(flag));
	int Min,i;
	for(i=1;i<=N;i++)
		dist[i]=edge[N][i];
	while(1)
	{
		for(Min=1;flag[Min]==true;Min++);
		for(i=Min+1;i<N;i++)
			if(!flag[i])
				if(dist[i]<dist[Min])
					Min=i;
		flag[Min]=true;
		if(Min==1)
			return dist[1];
		for(i=1;i<N;i++)
			if(!flag[i])
			{
				if(dist[Min]+edge[Min][i]<dist[i])
					dist[i]=dist[Min]+edge[Min][i];
			}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,b,c;
	scanf("%d%d",&T,&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			edge[i][j]=Inf;
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		edge[a][b]=c;
		edge[b][a]=c;
	}
	printf("%d\n",dijk());
	return 0;
}