#include<iostream>
using namespace std;

struct point 
{
	double x,y;
};

struct Line
{
	point u,v;
}line[100002];
bool is[100002];
int top[1003];

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判三点共线
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}

//判点是否在线段上,包括端点
int dot_online_in(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}

//判两点在线段同侧,点在线段上返回0

int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

//判两线段相交,包括端点和部分重合

int intersect_in(point u1,point u2,point v1,point v2){
	if (!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
		return !same_side(u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
	return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,cnt;
	while(scanf("%d",&n)!=EOF&&n)
	{
		cnt=0;
		memset(is,0,sizeof(is));
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&line[i].u.x,&line[i].u.y,&line[i].v.x,&line[i].v.y);
		for(i=0;i<n-1;i++)
		{
			if(!is[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(intersect_in(line[i].u,line[i].v,line[j].u,line[j].v))
					{
						is[i]=true;
						break;
					}
				}
				if(j==n)
				{
					top[cnt]=i;
					cnt++;
				}
			}
		}
		printf("Top sticks:");
		for(i=0;i<cnt;i++)
			printf(" %d,",top[i]+1);
		printf(" %d",n);
		printf(".\n");
	}
	//printf("%d\n",intersect_in(line[0].u,line[0].v,line[2].u,line[2].v));
	return 0;
}