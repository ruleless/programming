#include<iostream>
using namespace std;

int main()
{
	int parent[10005]={0},parent1[10005]={0},hash[10005]={0};
	//freopen("in.txt","r",stdin);
	int t,N,i,j,a1,a2,i1;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&N);
		for(j=0;j<=N;j++)
		{
			hash[j]=0;
			parent[j]=0;
		}
		while(1)
		{
			scanf("%d%d",&a1,&a2);
			if(parent[a2]!=0)
				break;
			parent[a2]=a1;
		}
		i1=1;
		while(a1!=0)
		{
			parent1[i1]=a1;hash[a1]=i1;a1=parent[a1];i1++;
		}
		while(a2!=0)
		{
			if(hash[a2]==0)
				a2=parent[a2];
			else
				break;
		}			
		printf("%d\n",a2);
	}
	return 0;
}
