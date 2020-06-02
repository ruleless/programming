#include<iostream>
#include<cstring>
using namespace std;

double dist[35];
struct node{
	int beg,end;
	double cost;
};
struct node edge[400];
int cnt,n;
char money[35][30];

void relax(struct node edge1)
{
	if(dist[edge1.beg]*edge1.cost>dist[edge1.end])
		dist[edge1.end]=dist[edge1.beg]*edge1.cost;
}


void Ford(int v)
{
	int i,j;
	dist[v]=1;
	for(i=1;i<=n;i++)
		if(i!=v)
	    	dist[i]=0;
	for(i=1;i<=n-1;i++)
		for(j=0;j<cnt;j++)
			relax(edge[j]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,cse=0;
	double x;
	char c1[30],c2[30];
	while(scanf("%d",&n),n)
	{
		cse++;
		for(i=1;i<=n;i++)
		{
			scanf("%s",money[i]);
		//	printf("%s\n",money[i]);
		}
		scanf("%d",&cnt);
		for(k=0;k<cnt;k++)
		{
			scanf("%s %lf %s",c1,&x,c2);
		//	printf("%s %lf %s\n",c1,x,c2);
			for(i=1;strcmp(c1,money[i])!=0;i++);
			for(j=1;strcmp(c2,money[j])!=0;j++);
			edge[k].beg=i;edge[k].end=j;
			edge[k].cost=x;
		}	
		for(i=1;i<=n;i++)
		{
	    	Ford(i);
	    	if(dist[i]>1.0)
			{
		    	printf("Case %d: Yes\n",cse);
    			break;
			}
		}
		if(i==n+1)
			printf("Case %d: No\n",cse);
	}
	return 0;
}
