#include<iostream>
using namespace std;

#define N 10000
bool isprim[N+1];
void prim()
{
    for (int i=0;i<=N;i++)
        isprim[i]=true;
    isprim[0]=false;
    isprim[1]=false;
    for (i=2;i<=5000;i++)
        if (isprim[i])
            for (int j=2;i*j<=N;j++)
                    isprim[i*j]=false;
}

int num[1300];

bool is(int i,int n)
{
	int sum=0,j;
	for(j=i;sum<n;j++)
		sum+=num[j];
	if(sum==n)
		return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,cnt=0;
	prim();
	for(i=2;i<=10000;i++)
		if(isprim[i])
		{
			num[cnt]=i;
		//	printf("%d ",i);
			cnt++;
		}
//	printf("\n%d",cnt);
	while(scanf("%d",&n)!=EOF&&n)
	{
		j=0;
		for(i=0;num[i]<=n;i++)
			if(is(i,n))
				j++;
		printf("%d\n",j);
	}
	return 0;
}