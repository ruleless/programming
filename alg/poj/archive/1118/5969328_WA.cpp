#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159256

struct node
{
	int x,y;
}point[707];

double rad[707];

int cmp(const void* a,const void* b)
{
	if( *(double*)a<*(double*)b )
		return -1;
	else if( *(double*)a==*(double*)b )
		return 0;
	else 
		return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,k,cnt,a,b,Max;
	while(scanf("%d",&n)!=EOF&&n)
	{
		cnt=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&point[i].x,&point[i].y);
		k=0;
		for(i=1;i<n;i++)
		{
			if(point[i].y<point[k].y)
				k=i;
			else if(point[i].y==point[k].y)
			{
				if(point[i].x<point[k].x)
					k=i;
			}
		}
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(i!=k)
			{
				a=point[i].x-point[k].x;
				b=point[i].y-point[k].y;
				if(b==0)
				{
					rad[cnt]=pi/2;
				}
				else if(a<0)
				{
					rad[cnt]=pi-atan(-1.0*b/a);
				}
				else
				{
					rad[cnt]=atan(1.0*b/a);
				}
				cnt++;
			}
		}
		qsort(rad,cnt,sizeof(double),cmp);
		Max=0;
		a=1;
		for(i=0;i<n-1;i++)
		{
			if(rad[i+1]==rad[i])
				a++;
			else 
			{
				a=1;
			}
			if(a>Max)
				Max=a;
		}
		printf("%d\n",Max+1);
	//	for(i=0;i<cnt;i++)
		//	printf("%.18lf\n",rad[i]);
	}
	return 0;
}