#include<iostream>
using namespace std;

int num[100001];

int cmp(const void*a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int N,K,d,i;
	char c[4];
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	//printf("%d",N);
	qsort(num,N,sizeof(int),cmp);
	/*for(i=0;i<N;i++)
		printf("%d\n",num[i]);*/
	scanf("%s",c);
	scanf("%d",&K);
	for(i=1;i<=K;i++)
	{
		scanf("%d",&d);
		printf("%d\n",num[d-1]);
	}
	return 0;
}
