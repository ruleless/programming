#include<iostream>
#define Max 5000000
using namespace std;

struct node{
	int low,high;
};

struct node lev[150];
int level[150];
int Vex[150];
int flag[150]={0};
int edge[150][150];

int dist[150];

int main()
{
//	freopen("in.txt","r",stdin);
	int M,N,P,L,X,i,j,k,min,a,m;
	scanf("%d%d",&M,&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			edge[i][j]=Max;
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&P,&L,&X);
	//	printf("%d %d %d\n",P,L,X);
		Vex[i]=P;level[i]=L;
		for(j=1;j<=X;j++)
		{
			scanf("%d%d",&L,&P);
		//	printf("%d %d\n",L,P);
			edge[i][L]=P;
		}
	}

	for(i=2;i<=N;i++)
	{
		if(abs(level[i]-level[1])>M)
			dist[i]=-1;
		else
		{
			dist[i]=edge[1][i];
			lev[i].high=(level[i]>level[1])?level[i]:level[1];
			lev[i].low=(level[i]<=level[1])?level[i]:level[1];
		}
	}
	for(i=1;i<=N-2;i++)
	{
		j=2;
		while(dist[j]==-1||flag[j]==1)j++;
		k=j;
		for(m=j+1;m<=N;m++)
			if(dist[m]!=-1&&flag[m]==0&&dist[m]<dist[k])
				k=m;
		flag[k]=1;
		for(j=2;j<=N;j++)
		{
			if(flag[j]==0&&dist[j]!=-1&&(edge[k][j]+dist[k])<dist[j]&&abs(level[j]-lev[k].high)<=M&&abs(level[j]-lev[k].low)<=M)
			{
				dist[j]=dist[k]+edge[k][j];
				a=lev[k].high;
				if(lev[k].low<a)a=lev[k].low;
				if(level[j]<a)a=level[j];
				lev[j].low=a;
				a=lev[k].high;
				if(lev[k].low>a)a=lev[k].low;
				if(level[j]>a)a=level[j];
				lev[j].high=a;
			}
		}
	}
	min=Vex[1];
	for(i=2;i<=N;i++)
		if(dist[i]!=-1)
			dist[i]+=Vex[i];
	for(j=2;j<=N;j++)
		if(dist[j]!=-1&&dist[j]<min)
			min=dist[j];
	printf("%d\n",min);



	return 0;
}