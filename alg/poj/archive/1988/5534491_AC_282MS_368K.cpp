#include<iostream>
#include<cstring>
using namespace std;

int cube[30001];
int sum[30001];

int Find(int x)
{
	if(cube[x]<0)
		return x;
	int r=Find(cube[x]);
	sum[x]+=sum[cube[x]];
	cube[x]=r;
	return r;
}

void Union(int x,int y)
{
	int a=Find(x),b=Find(y);
	if(a==b)
		return;
	sum[b]=-cube[a];
	cube[a]+=cube[b];
	cube[b]=a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y,t,i;
	char c[3];
	for(i=0;i<30001;i++)
	{
		cube[i]=-1;
		sum[i]=0;
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%s",c);
		if(strcmp(c,"M")==0)
		{
			scanf("%d%d",&x,&y);
			//printf("M %d%d\n",x,y);
			Union(x,y);
		}
		else if(strcmp(c,"C")==0)
		{
			scanf("%d",&x);
			int r=Find(x);
			//printf("C %d\n",x);
			printf("%d\n",-cube[r]-sum[x]-1);
		}
	}
	return 0;
}