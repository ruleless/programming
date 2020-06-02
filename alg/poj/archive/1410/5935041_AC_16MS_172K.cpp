#include<iostream>
using namespace std;

struct point
{
	double x,y;
}u,v,t1,t2,t3,t4;

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
	int n;bool flag;
	scanf("%d",&n);
	while(n--)
	{
		flag=true;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&u.x,&u.y,&v.x,&v.y,&t1.x,&t1.y,&t3.x,&t3.y);
		t2.x=t1.x;
		t2.y=t3.y;
		t4.x=t3.x;
		t4.y=t1.y;
		if(intersect_in(u,v,t1,t2))
		{
			flag=false;
			printf("T\n");
		}
		else if(intersect_in(u,v,t2,t3))
		{
			flag=false;
			printf("T\n");
		}
		else if(intersect_in(u,v,t3,t4))
		{
			flag=false;
			printf("T\n");
		}
		else if(intersect_in(u,v,t1,t4))
		{
			flag=false;
			printf("T\n");
		}
		else if(( u.x>( (t1.x<t4.x)?t1.x:t4.x )&&u.x<( (t1.x>t4.x)?t1.x:t4.x ) )&&( u.y>( (t1.y<t2.y)?t1.y:t2.y )&&u.y<( (t1.y>t2.y)?t1.y:t2.y ) )
			&&( v.x>( (t1.x<t4.x)?t1.x:t4.x )&&v.x<( (t1.x>t4.x)?t1.x:t4.x ) )&&( v.y>( (t1.y<t2.y)?t1.y:t2.y )&&v.y<( (t1.y>t2.y)?t1.y:t2.y ) ))
		{
			flag=false;
			printf("T\n");
		}

		if(flag)
			printf("F\n");
	}
	return 0;
}