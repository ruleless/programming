#include<iostream>
using namespace std;

struct node
{
	int id,salary,height;
};
node ep[30011];
int hash[900011];

int cmp(const void*a,const void*b)
{
	return ((node*)a)->salary-((node*)b)->salary;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,q,i,j,id,k,l,cnt,m,boss[30001];	
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld%ld",&n,&q);
		for(j=0;j<n;j++)
		{
			scanf("%ld%ld%ld",&ep[j].id,&ep[j].salary,&ep[j].height);
		}
		qsort(ep,n,sizeof(node),cmp);
		for(j=0;j<n;j++)
			hash[ep[j].id-100000]=j;
		for(l=0;l<n-1;l++)
		{
			for(m=l+1;ep[m].height<ep[l].height;m++);
			boss[l]=m;
		}
		boss[l]=0;
		for(j=1;j<=q;j++)
		{
			cnt=0;
			scanf("%d",&id);
			k=hash[id-100000];
			if(k==n-1)
			{
				printf("0 %d\n",n-1);continue;
			}
			for(l=k+1;ep[l].height<ep[k].height;l++);			
			printf("%d ",ep[l].id);m=k;
			for(l=k-1;l>=0;l--)
				if(boss[l]==k||boss[l]==m)
				{
					cnt++;m=l;
				}
			printf("%d\n",cnt);
		}
	}
	return 0;
}