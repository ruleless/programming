#include<iostream>
using namespace std;
static int parent[10001],parent1[10001],parent2[10001],hash[10001];

int main()
{
	//freopen("in.txt","r",stdin);
	int t,N,i,j,a1,a2,c2,flag,i1,i2;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		for(j=1;j<10001;j++)
		{
			hash[j]=-1;
	    	parent[j]=0;
		}
		scanf("%d",&N);
		while(1)
		{
			scanf("%d%d",&a1,&a2);
			if(parent[a2]!=0)
				break;
			parent[a2]=a1;
		}
		//for(j=1;j<=N;j++)
			//printf("%d %d\n",j,parent[j]);
		c2=a2;flag=0;//printf("%d %d\n",a1,a2);
		i1=0;i2=0;
		while(a1!=0)
		{
			parent1[i1]=a1;hash[a1]=i1;a1=parent[a1];i1++;
		}
		while(a2!=0)
		{
			if(hash[a2]==-1)
				a2=parent[a2];
			else
				break;
		}
			
		printf("%d\n",a2);
	}
	return 0;
}
