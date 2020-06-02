#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[50005],p[50005][20],q[50005][20],i,j,k,n,nq,a,b,sa,ya,t;
int main()
{
	scanf("%d%d",&n,&nq);
	for (i=1;i<=n;i++) {scanf("%d",&f[i]);p[i][0]=f[i];q[i][0]=f[i];}
	for (j=1;j<=log((double)(n+1))/log(2.0);j++)
	for (i=1;i+(1<<j)-1<=n;i++)
	{
		p[i][j]=min(p[i][j-1],p[i+( 1<<(j-1) )][j-1]);
		q[i][j]=max(q[i][j-1],q[i+( 1<<(j-1) )][j-1]);
	}
	while(nq--)
	{
		scanf("%d%d",&a,&b);
		k=(int)(log((double)(b-a+1))/log(2.0));
		printf("%d\n", max( q[a][k],q[b-(1<<k)+1][k]) - min( p[a][k], p[b-(1<<k)+1][k] ) ) ;
	}
}
