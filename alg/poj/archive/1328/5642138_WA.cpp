#include<iostream>
#include<cmath>
using namespace std;

struct Node{
	double low,high;
};

struct Node node[1002];

int cmp(const void*a,const void*b)
{
	if(((struct Node*)a)->low==((struct Node*)b)->low)
	{
		if(((struct Node*)a)->high>((struct Node*)b)->high)
			return 1;
		else if(((struct Node*)a)->high<((struct Node*)b)->high)
			return -1;
		else 
			return 0;
	}
	else 
	{
		if(((struct Node*)a)->low>((struct Node*)b)->low)
			return 1;
		else if(((struct Node*)a)->low<((struct Node*)b)->low)
			return -1;
		else return 0;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,d,cnt=0,i,sum,a,b;
	bool flag;
	while(scanf("%d%d",&n,&d),!(n==0&&d==0))
	{
		sum=1;
		cnt++;
		flag=true;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(d<=0||abs(b)>d)
				flag=true;
			else if(abs(b)==d)
			{
				node[i].low=node[i].high=double(a);
			}
			else
			{
				node[i].low=(double)a-double(sqrt(double(d*d-b*b)));
				node[i].high=(double)a+double(sqrt(double(d*d-b*b)));
			}
		}
		if(flag==false)
			printf("Case %d: -1\n",cnt);
		else
		{
			qsort(node,n,sizeof(struct Node),cmp);
			b=0;
			for(a=1;a<n;a++)
			{
				if(node[a].low>node[b].high)
				{
					sum++;
					b=a;
				}
			}
			printf("Case %d: %d\n",cnt,sum);
		}
	}
	return 0;
}

