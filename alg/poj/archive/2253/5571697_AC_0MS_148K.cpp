#include<iostream>
#include<cmath>
using namespace std;

int flag[204];
struct node{
	int x,y;
};
struct node pos[204];
float closedge[204];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k,l,cse=0;
	float Max,x;
	while(scanf("%d",&n),n)
	{
		Max=0;cse++;
		scanf("%d%d",&pos[1].x,&pos[1].y);
		scanf("%d%d",&pos[n].x,&pos[n].y);
		for(i=2;i<=n-1;i++)
			scanf("%d%d",&pos[i].x,&pos[i].y);
		memset(flag,0,sizeof(flag));
		flag[1]=1;
		for(i=2;i<=n;i++)
			closedge[i]=sqrt(1.0*((pos[i].x-pos[1].x)*(pos[i].x-pos[1].x)+(pos[i].y-pos[1].y)*(pos[i].y-pos[1].y)));
		for(i=1;i<=n-1;i++)
		{
			j=2;
			while(flag[j]==1)j++;
			k=j;
			for(l=j+1;l<=n;l++)
				if(flag[l]==0&&closedge[l]<closedge[k])
					k=l;
			flag[k]=1;
			if(closedge[k]>Max)
				Max=closedge[k];
			if(k==n)
				break;
			for(j=2;j<=n;j++)
			{
				x=sqrt(1.0*((pos[j].x-pos[k].x)*(pos[j].x-pos[k].x)+(pos[j].y-pos[k].y)*(pos[j].y-pos[k].y)));
				if(flag[j]==0&&x<closedge[j])
					closedge[j]=x;
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",cse,Max);
	}
	return 0;
}
