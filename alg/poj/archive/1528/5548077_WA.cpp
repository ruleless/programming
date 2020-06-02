#include<iostream>
using namespace std;


int main()
{
	//freopen("in.txt","r",stdin);
	int array[102],j,n=0,i,sum;
	while(scanf("%d",&array[n]),array[n]!=0)n++;
	printf("PERFECTION OUTPUT\n");
	for(i=0;i<n;i++)
	{
		sum=1;
		for(j=2;j<=array[i]/2;j++)
			if(array[i]%j==0)
				sum+=j;
		if(sum==array[i])
			printf("%5d  PERFECT\n",array[i]);
		else if(sum<array[i])
			printf("%5d  DEFICIENT\n",array[i]);
		else if(sum>array[i])
			printf("%5d  ABUNDANT\n",array[i]);
	}
	printf("END OF OUTPUT\n");

	return 0;
}
