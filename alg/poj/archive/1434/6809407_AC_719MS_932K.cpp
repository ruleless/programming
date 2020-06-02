#include<iostream>
using namespace std;

struct Box
{
	int b,h,w,d;
}box[50005];
int n,v;
double res;

int equals(double height)
{
	double sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		if((box[i].b+box[i].h)*1.0<height)
		{
			sum+=(box[i].h*box[i].w*box[i].d)*1.0;
		}
		else if(height>box[i].b*1.0)
		{
			sum+=((-box[i].b+height)*box[i].w*box[i].d)*1.0;
		}
		if(sum>1.0*v)
			return -1;
	}
	if(sum==1.0*v)
	{
		return 0;
	}
	if(sum<1.0*v)
	{
		return 1;
	}
}

void bina(double beg,double end)
{
	double mid=(beg+end)/2;
	if(equals(mid)==0)
	{
		res=mid;
		return ;
	}
	if(end-beg<0.001)
	{
		res=mid;
		return;
	}
	if(equals(mid)==-1)
	{
		end=mid;
		bina(beg,end);
	}
	else
	{
		beg=mid;
		bina(beg,end);
	}
}

void deal()
{
	int i;
	double temp=0;
	for(i=0;i<n;i++)
	{
		if(res>box[i].b*1.0&&res<=(box[i].b+box[i].h)*1.0)
			return;
		if(1.0*(box[i].b+box[i].h)<res)
		{
			if(1.0*(box[i].b+box[i].h)>temp)
				temp=1.0*(box[i].b+box[i].h);
		}
	}
	res=temp;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j;
	double beg=10e30,end=0;
	scanf("%d",&t);
	while(t--)
	{
		res=-1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&box[i].b,&box[i].h,&box[i].w,&box[i].d);
			if(box[i].b*1.0<beg)
				beg=box[i].b*1.0;
			if((box[i].b+box[i].h)*1.0>end)
				end=(box[i].b+box[i].h)*1.0;
		}
		scanf("%d",&v);
		if(equals(end)==1)
		{
			printf("OVERFLOW\n");
			continue;
		}
		bina(beg,end);
		deal();
		printf("%.2lf\n",res);
	}
	return 0;
}