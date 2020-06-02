#include<iostream>
#include<cstring>
using namespace std;

float dist[35];
struct node{
	int beg,end;
	float cost;
};
struct node edge[95];
int cnt,n;
char money[35][30];

void relax(struct node edge1)
{
	if(dist[edge1.beg]*(edge1.cost)>dist[edge1.end])
		dist[edge1.end]=dist[edge1.beg]*(edge1.cost);
}


void Ford()
{
	int i,j;
	dist[1]=1;
	for(i=2;i<=n;i++)
		dist[i]=0;
	for(i=1;i<=n-1;i++)
		for(j=0;j<cnt;j++)
			relax(edge[j]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,cse=0;
	float x;
	char c1[30],c2[30];
	while(scanf("%d",&n),n)
	{
		cnt=0;
		cse++;
		for(i=1;i<=n;i++)
		{
			scanf("%s",money[i]);
		//	printf("%s\n",money[i]);
		}
		scanf("%d",&cnt);
		for(k=0;k<cnt;k++)
		{
			scanf("%s%f%s",c1,&x,c2);
			for(i=1;strcmp(money[i],c1)!=0;i++);
			for(j=1;strcmp(money[j],c2)!=0;j++);
			edge[k].beg=i;edge[k].end=j;
			edge[k].cost=x;
		}	

	   	Ford();
	    if(dist[1]>1.0)
		{
		   	printf("Case %d: Yes\n",cse);
		}
		else
			printf("Case %d: No\n",cse);
	}
	return 0;
}
