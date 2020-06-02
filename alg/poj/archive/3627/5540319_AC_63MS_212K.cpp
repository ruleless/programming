#include<iostream>
using namespace std;

unsigned int cows[20001];


int cmp(const void*a,const void*b)
{
	return -int(*(unsigned int*)a-*(unsigned int*)b);
}


int main()
{
//	freopen("in.txt","r",stdin);
	unsigned int N,B,i,sum=0;
	scanf("%u%u",&N,&B);
	for(i=0;i<N;i++)
		scanf("%u",&cows[i]);
	qsort(cows,N,sizeof(unsigned int),cmp);
	for(i=0;sum<B;i++)
		sum+=cows[i];
	printf("%u\n",i);
	return 0;
}
