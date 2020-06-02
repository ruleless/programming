#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-8
int n;
struct Point
{
	double x,y;
};

struct Seg
{
	struct Point A,B;
}seg[150];

bool check(struct Point A,struct Point B,struct Point C,struct Point D)
{
	struct Point tp1,tp2,tp3;
	tp1.x=C.x-A.x;tp1.y=C.y-A.y;
	tp2.x=B.x-A.x;tp2.y=B.y-A.y;
	tp3.x=D.x-A.x;tp3.y=D.y-A.y;
	double res1,res2;
	res1=tp2.x*tp1.y-tp1.x*tp2.y;
	res2=tp3.x*tp2.y-tp2.x*tp3.y;
	if(res1*res2>=0)
		return true;
	return false;
}

bool f(struct Point A,struct Point B,int i,int j)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(k!=j&&k!=i)
		{
			if(!check(A,B,seg[k].A,seg[k].B))
				return false;
		}
	}
	return true;
}

bool work()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if( !( fabs(seg[i].A.x-seg[j].A.x)<eps&&fabs(seg[i].A.y-seg[j].A.y)<eps ) )
			{
				if( f(seg[i].A,seg[j].A,i,j) )
					return true;
			}
			if( !( fabs(seg[i].A.x-seg[j].B.x)<eps&&fabs(seg[i].A.y-seg[j].B.y)<eps ) )
			{
				if( f(seg[i].A,seg[j].B,i,j) )
					return true;
			}
			if( !( fabs(seg[i].B.x-seg[j].A.x)<eps&&fabs(seg[i].B.y-seg[j].A.y)<eps ) )
			{
				if( f(seg[i].B,seg[j].A,i,j) )
					return true;
			}
			if( !( fabs(seg[i].B.x-seg[j].B.x)<eps&&fabs(seg[i].B.y-seg[j].B.y)<eps ) )
			{
				if( f(seg[i].B,seg[j].B,i,j) )
					return true;
			}
		}
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&seg[i].A.x,&seg[i].A.y,&seg[i].B.x,&seg[i].B.y);
		}
		if(work())
		{
			printf("Yes!\n");
		}
		else 
		{
			printf("No!\n");
		}
	}
	return 0;
}