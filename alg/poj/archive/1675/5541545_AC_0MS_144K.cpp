#include<iostream>
#include<cmath>
#define pi 3.14159256
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int t,r,x1,y1,x2,y2,x3,y3,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d%d%d%d%d",&r,&x1,&y1,&x2,&y2,&x3,&y3);
		double cosa=double(x1*x1+y1*y1+x2*x2+y2*y2-(x1-x2)*(x1-x2)-(y1-y2)*(y1-y2))/(2*sqrt(double(x1*x1+y1*y1))*sqrt(double(x2*x2+y2*y2)));
		double cosb=double(x1*x1+y1*y1+x3*x3+y3*y3-(x1-x3)*(x1-x3)-(y1-y3)*(y1-y3))/(2*sqrt(double(x1*x1+y1*y1))*sqrt(double(x3*x3+y3*y3)));
		double cosc=double(x3*x3+y3*y3+x2*x2+y2*y2-(x3-x2)*(x3-x2)-(y3-y2)*(y3-y2))/(2*sqrt(double(x3*x3+y3*y3))*sqrt(double(x2*x2+y2*y2)));
		if((x1==0&&y1==0)||(x2==0&&y2==0)||(x3==0&&y3==0))
			printf("No\n");
		else if(cosa<-.5||cosb<-.5||cosc<-.5)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}