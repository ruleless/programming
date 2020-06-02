#include<iostream>
using namespace std;

struct node
{
	int id,salary,height;
};
node ep[30000];
int hash[900000]={0};

int cmp(const void*a,const void*b)
{
	return ((node*)a)->salary-((node*)b)->salary;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,q,i,j,id,k,l,cnt,m;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&q);
		for(j=0;j<n;j++)
		{
			scanf("%d%d%d",&ep[j].id,&ep[j].salary,&ep[j].height);
		//	printf("%d %d %d\n",ep[j].id,ep[j].salary,ep[j].height);
		}
		qsort(ep,n,sizeof(node),cmp);
		for(j=0;j<n;j++)
			hash[ep[j].id-100000]=j;

		//for(j=0;j<n;j++)
			//printf("%d %d %d\n",ep[j].id,ep[j].salary,ep[j].height);
		for(j=1;j<=q;j++)
		{
			cnt=0;
			scanf("%d",&id);
			k=hash[id-100000];
			for(l=k+1;l<n&&ep[l].height<ep[k].height;l++);
			if(l==n)
			{
				printf("0 %d\n",n-1);continue;
			}
			else
				printf("%d ",ep[l].id);
			for(l=0;l<k;l++)
			{
				for(m=l+1;m<=k&&ep[m].height<ep[l].height;m++);
				if(m==k)cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}

