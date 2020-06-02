#include<iostream>
using namespace std;

int cnt(int n)
{
	int i,j,cnt,c=0;
	for(i=1;i<=n;i++)
	{
		cnt=i;
		for(j=i+1;cnt<n;j++)
			cnt+=j;
		if(cnt==n)
			c++;
	}
	return c;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int N;
	scanf("%d",&N);
	printf("%d\n",cnt(N));
	return 0;
}