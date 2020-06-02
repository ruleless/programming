#include<iostream>
using namespace std;
static int parent[10001];

int main()
{
	//freopen("in.txt","r",stdin);
	int t,N,i,j,a1,a2,c2,flag;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		for(j=1;j<10001;j++)
	    	parent[j]=0;
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
		while(a1!=0)
		{
			a2=c2;
			while(a2!=0)
			{
				//printf("%d %d %d\n",a2,a1,flag);
				if(a1==a2)
				{
					flag=1;break;
				}
				a2=parent[a2];
			}
			if(flag==1)
				break;
			a1=parent[a1];
		}
		printf("%d\n",a1);
	}
	return 0;
}
