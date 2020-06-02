#include<iostream>
#include<cmath>
using namespace std;


struct nod
{
	int x,y;
	bool operator<(const struct nod &aa)const
	{
		if(x==aa.x)
			return y<aa.y;
		else
			return x<aa.x;
	}
}temp1,temp2;

int cmp(const void*a,const void*b)
{
	if(((struct nod*)a)->x==((struct nod*)b)->x)
		return ((struct nod*)a)->y-((struct nod*)b)->y;
	else 
		return ((struct nod*)a)->x-((struct nod*)b)->x;
}

struct nod vex[1003];

int main()
{
//	freopen("in.txt","r",stdin);
	int x1,x2,y1,y2;
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&vex[i].x,&vex[i].y);
		}
		qsort(vex,n,sizeof(struct nod),cmp);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
					x1=vex[i].x;
					x2=vex[j].x;
					y1=vex[i].y;
					y2=vex[j].y;
					if( (y1-y2+x1+x2)%2!=0 )
						continue;
					temp1.x=(y1-y2+x1+x2)/2;
					if( (-x1+x2+y1+y2)%2!=0 )
						continue;
					temp1.y=(-x1+x2+y1+y2)/2;
					if(bsearch(&temp1,vex,n,sizeof(struct nod),cmp)==NULL )
						continue;
					if( (-y1+y2+x1+x2)%2!=0 )
						continue;
					temp1.x=(-y1+y2+x1+x2)/2;
					if( (x1-x2+y1+y2)%2!=0 )
						continue;
					temp1.y=(x1-x2+y1+y2)/2;
					if(bsearch(&temp1,vex,n,sizeof(struct nod),cmp)!=NULL )
						k++;

			}
		printf("%d\n",k/2);
	}
	return 0;
}
