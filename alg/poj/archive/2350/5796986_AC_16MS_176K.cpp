#include<iostream>
using namespace std;

int s[1001];

int main()
{
	int C,N,i,j,sum,k;
	scanf("%d",&C);
	for(i=1;i<=C;i++)
	{
		sum=0;
		scanf("%d",&N);
		for(j=0;j<N;j++)
		{
			scanf("%d",&s[j]);
			sum+=s[j];
		}
		k=0;
		for(j=0;j<N;j++)
			if(s[j]>sum*1.0/N)
				k++;
		printf("%.3f%%\n",k*100.0/N);
	}
	return 0;
}
