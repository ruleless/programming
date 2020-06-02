#include<iostream>
using namespace std;

struct Node
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
}node[15];

struct Point
{
	int x,y;
};

int f(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	struct Point tp1,tp2,tp3;
	tp1.x=x1-x3;
	tp1.y=y1-y3;
	tp2.x=x4-x3;
	tp2.y=y4-y3;
	tp3.x=x2-x3;
	tp3.y=y2-y3;
	int res1=tp2.x*tp1.y-tp1.x*tp2.y;
	int res2=tp3.x*tp2.y-tp2.x*tp3.y;
	if(res1==0&&res2==0)
		return 2;
	if(res1*res2>=0)
		return 1;
	return 0;
}

void solve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,double& x,double& y)
{
	double k1,k2;
	if(x1==x2)
	{
		x=x1;
		k2=(y3-y4)*1.0/(x3-x4);
		y=k2*(x-x3)+y3;
	}
	else if(x3==x4)
	{
		x=x3;
		k1=(y1-y2)*1.0/(x1-x2);
		y=k1*(x-x1)+y1;
	}
	else
	{
		k1=(y1-y2)*1.0/(x1-x2);
		k2=(y3-y4)*1.0/(x3-x4);
		x=(y3-y1+k1*x1-k2*x3)/(k1-k2);
		y=k1*(x-x1)+y1;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int x1,y1,x2,y2,x3,y3,x4,y4,t,i;
	double x,y;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d%d%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2,&node[i].x3,&node[i].y3,&node[i].x4,&node[i].y4);
	}
	printf("INTERSECTING LINES OUTPUT\n");
	for(i=0;i<t;i++)
	{
		if(f(node[i].x1,node[i].y1,node[i].x2,node[i].y2,node[i].x3,node[i].y3,node[i].x4,node[i].y4)==0)
		{
			printf("NONE\n");
		}
		else if(f(node[i].x1,node[i].y1,node[i].x2,node[i].y2,node[i].x3,node[i].y3,node[i].x4,node[i].y4)==2)
		{
			printf("LINE\n");
		}
		else
		{
			solve(node[i].x1,node[i].y1,node[i].x2,node[i].y2,node[i].x3,node[i].y3,node[i].x4,node[i].y4,x,y);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}