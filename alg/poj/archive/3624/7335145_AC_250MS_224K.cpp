#include <iostream>
#include <cstdio>

using namespace std;

int c[4000],w[4000],V,f[14000],n;

int maxf(int a,int b)
{
	return a>b?a:b;
}

int onepack()
{
	int i,j,k,v;
	for(i=1;i<=n;i++)
	{
		for(v=V;v>=c[i];v--)
		{
			f[v]=maxf(f[v],f[v-c[i]]+w[i]);
		}
	}
	return f[V];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d%d",&n,&V);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&w[i]);
	}
	printf("%d\n",onepack());
	return 0;
}