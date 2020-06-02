#include<iostream>
using namespace std;

struct Point
{
	int x,y;
}pnt[5006];

int cnt[5006];

bool include(struct Point E,struct Point A,struct Point B,struct Point C,struct Point D)
{
	int x1,y1,x2,y2;
	x1=E.x-A.x;
	y1=E.y-A.y;
	x2=B.x-A.x;
	y2=B.y-A.y;
	if(x1*y2<x2*y1)
		return false;
	x1=E.x-B.x;
	y1=E.y-B.y;
	x2=C.x-B.x;
	y2=C.y-B.y;
	if(x1*y2<x2*y1)
		return false;
	x1=E.x-C.x;
	y1=E.y-C.y;
	x2=D.x-C.x;
	y2=D.y-C.y;
	if(x1*y2<x2*y1)
		return false;
	x1=E.x-D.x;
	y1=E.y-D.y;
	x2=A.x-D.x;
	y2=A.y-D.y;
	if(x1*y2<x2*y1)
		return false;
	return true;
}

int main()
{
	int n,m,x1,y1,x2,y2,i,j;
	struct Point A,B,C,D,E;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&pnt[i].x,&pnt[i].y);
		}
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<m;i++)
		{
			bool flag=true;
			scanf("%d%d",&E.x,&E.y);
			A.x=x1;A.y=y1;
			B.x=pnt[0].x;B.y=y1;
			C.x=pnt[0].y;C.y=y2;
			D.x=x1;D.y=y2;
			if(include(E,A,B,C,D))
			{
				cnt[0]++;
				flag=false;
			}
			if(flag)
			{
				for(j=0;j<n-1;j++)
				{
					A.x=pnt[j].x;A.y=y1;
					B.x=pnt[j+1].x;B.y=y1;
					C.x=pnt[j+1].y;C.y=y2;
					D.x=pnt[j].y;D.y=y2;
					if(include(E,A,B,C,D))
					{
						cnt[j+1]++;
						flag=false;
						break;
					}
				}
			}
			if(flag)
			{
				A.x=pnt[n-1].x;A.y=y1;
				B.x=x2;B.y=y1;
				C.x=x2;C.y=y2;
				D.x=pnt[n-1].y;D.y=y2;
				if(include(E,A,B,C,D))
				{
					cnt[n]++;
				}
			}
		}
		for(i=0;i<=n;i++)
		{
			printf("%d: %d\n",i,cnt[i]);
		}
		printf("\n");
	}
	return 0;
}