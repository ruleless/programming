#include<iostream>
using namespace std;

bool lock[101];

int main()
{
	int n,t,i,j,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(lock,0,sizeof(lock));
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j+=i)
			{
				if(lock[j]==true)
					lock[j]=false;
				else
					lock[j]=true;
			}
		sum=0;
		for(i=1;i<=n;i++)
			if(lock[i])
				sum++;
		printf("%d\n",sum);
	}
	return 0;
}