#include<iostream>
#include<cstring>
#include<cmath>
#define Max 1002
using namespace std;

struct node
{
	int status,x,y,parent;
};

node jsj[Max];

int Find(int x)
{
	if(jsj[x].parent<0)
		return x;
	int r=Find(jsj[x].parent);
	jsj[x].parent=r;
	return r;
}

void Union(int x,int y)
{
	int a=Find(x),b=Find(y);
	if(a==b)
		return;
	jsj[a].parent+=jsj[b].parent;
	jsj[b].parent=a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int N,d,i,j;
	char str[3];
	for(i=0;i<Max;i++)
	{
		jsj[i].x=0;jsj[i].y=0;
		jsj[i].status=0;jsj[i].parent=-1;
	}
	scanf("%d%d",&N,&d);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&jsj[i].x,&jsj[i].y);
	}
	while(scanf("%s",str)!=EOF)
	{
		if(strcmp(str,"O")==0)
		{
			scanf("%d",&i);
			jsj[i].status=1;
			for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				{
					if(jsj[j].status==1&&jsj[i].status==1&&sqrt(double((jsj[j].x-jsj[i].x)*(jsj[j].x-jsj[i].x)+(jsj[j].y-jsj[i].y)*(jsj[j].y-jsj[i].y)))<=double(d))
						Union(i,j);
				}
		}
		else if(strcmp(str,"S")==0)
		{
			scanf("%d%d",&i,&j);//printf("%d %d %d %d\n",i,j,Find(i),Find(j));
			if(Find(i)==Find(j))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}