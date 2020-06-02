#include<iostream>
#include<cmath>
using namespace std;

int x1,yy1,n,cnt;

struct Xline
{
	double beg,end;
}res[506],fres[506];

int cmp(const void* a,const void * b)
{
	if( ((struct Xline*)a)->beg<((struct Xline*)b)->beg )
		return -1;
	else if( ((struct Xline*)a)->beg>((struct Xline*)b)->beg )
		return 1;
	else return 0;
}

void deal()
{
	int i;
	
	fres[cnt].beg=res[0].beg;
	for(i=1;i<n;i++)
	{
		if(res[i].beg>res[i-1].end)
		{
			fres[cnt++].end=res[i-1].end;
			fres[cnt].beg=res[i].beg;
		}
	}
	fres[cnt++].end=res[i-1].end;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,x0,y0,r;
	double k1,k2,dlt,beg,end;
	while(scanf("%d",&n)!=EOF&&n)
	{
		cnt=0;
		scanf("%d%d",&x1,&yy1);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&x0,&y0,&r);
			if(x0-r==x1)
			{
				res[i].beg=x1;
				res[i].end=2.*r*yy1*(yy1-y0)/( (yy1-y0)*(yy1-y0)-r*r )+x1;
				continue;
			}
			if(x0+r==x1)
			{
				res[i].end=x1;
				res[i].beg=-2.*r*yy1*(yy1-y0)/( (yy1-y0)*(yy1-y0)-r*r )+x1;
				continue;
			}
			dlt=sqrt( 4.*(x0-x1)*(x0-x1)*(y0-yy1)*(y0-yy1)-4.*( (y0-yy1)*(y0-yy1)-r*r )*( (x0-x1)*(x0-x1)-r*r ) );
			
			k1=( 2.*(x0-x1)*(y0-yy1)-dlt )/( 2.0*( (x0-x1)*(x0-x1)-r*r ) );
			
			k2=( 2.*(x0-x1)*(y0-yy1)+dlt )/( 2.0*( (x0-x1)*(x0-x1)-r*r ) );

			beg=x1-1.0*yy1/k1;
			end=x1-1.0*yy1/k2;
			res[i].beg=(beg<end)?beg:end;
			res[i].end=(beg>end)?beg:end;
		}
		qsort(res,n,sizeof(struct Xline),cmp);
		deal();
		for(i=0;i<cnt;i++)
		{
			printf("%.2lf %.2lf\n",fres[i].beg,fres[i].end);
		}
		printf("\n");
	}
	return 0;
}