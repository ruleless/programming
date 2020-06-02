#include<iostream>
using namespace std;

int cow[100000];

int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&cow[i]);
	qsort(cow,N,sizeof(int),cmp);
	printf("%d\n",cow[(N-1)/2]);
	return 0;
}