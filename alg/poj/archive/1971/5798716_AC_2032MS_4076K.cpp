#include<iostream>
using namespace std;

struct node{
	int x,y;
}a[1001],p[1000*1000];

int cmp(const void*b,const void*c)
{
	if( ((struct node*)b)->x==((struct node*)c)->x )
		return ((struct node*)b)->y-((struct node*)c)->y;
	return ((struct node*)b)->x-((struct node*)c)->x;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,k,cnt;
	scanf("%d",&t);
	while(t--)
	{
		k=0;cnt=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				p[k].x=a[i].x+a[j].x;
				p[k].y=a[i].y+a[j].y;
				k++;
			}
		qsort(p,k,sizeof(struct node),cmp);
		j=1;
		for(i=1;i<k;i++)
		{
		//	printf("%d %d\n",p[i].x,p[i].y);
			if(p[i].x==p[i-1].x&&p[i].y==p[i-1].y)
				j++;
			else
			{
				cnt+=j*(j-1)/2;
				j=1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
				