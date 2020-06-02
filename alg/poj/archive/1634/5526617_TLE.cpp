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

bool isbo(int l,int*bo,int k)
{
	int i;
	for(i=0;i<k&&bo[i]!=l;i++);
	if(i==k)
		return false;
	return true;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,q,i,j,id,k,l,cnt,m,boss[30011],bo[30001];	
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&q);
		for(j=0;j<n;j++)
		{
			scanf("%d%d%d",&ep[j].id,&ep[j].salary,&ep[j].height);
		}
		qsort(ep,n,sizeof(node),cmp);
		for(j=0;j<n;j++)
			hash[ep[j].id-100000]=j;
		for(l=0;l<n-1;l++)
		{
			for(m=l+1;ep[m].height<ep[l].height;m++);
			boss[l]=m;//printf("%d\n",boss[l]);
		}
		boss[l]=0;//printf("%d\n",boss[l]);
		for(j=1;j<=q;j++)
		{
			cnt=0;
			scanf("%d",&id);
			k=hash[id-100000];
			if(k==n-1)
				printf("0 ");
			else
				printf("%d ",ep[boss[k]].id);
			m=k;bo[cnt]=k;
			for(l=k-1;l>=0;l--)
				if(isbo(boss[l],bo,cnt+1))
				{
					cnt++;bo[cnt]=l;
				}
			printf("%d\n",cnt);
		}
	}
	return 0;
}