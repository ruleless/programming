#include <iostream>
#include <cstdio>

using namespace std;

#define Max(a,b) a>b?a:b

double height[1005];
int n,m1[1005],m2[1005];
int res;

void dp()
{
	res=0;
	int i,j,k;
	m1[0]=1;
	m2[0]=1;
	for(i=1;i<n;i++)
	{
		m1[i]=1;
		m2[i]=1;
		for(j=0;j<i;j++)
		{
			if(height[i]>height[j])
			{
				m1[i]=Max(m1[i],m1[j]+1);
				if(m1[i]>res)
				{
					res=m1[i];
				}
			}
			if(height[i]<height[j])
			{
				m2[i]=Max(m2[i],m2[j]+1);
				if(m2[i]>res)
				{
					res=m2[i];
				}
			}
		}
	}
	printf("%d\n",n-res);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&height[i]);
	}
	dp();
	return 0;
}
