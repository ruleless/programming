#include<iostream>
using namespace std;

int s[102];

int cmp(const void*a,const void* b)
{
	return *((int*)a)-*((int*)b);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,sum;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		qsort(s,n,sizeof(int),cmp);
		sum=0;
		for(i=1;i<n-1;i++)
			sum+=s[i];
		//printf("%d\n",sum);
		printf("%d\n",sum/(n-2));
	}
	return 0;
}