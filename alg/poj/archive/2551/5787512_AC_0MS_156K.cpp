#include<stdio.h>
#include<math.h>
int main()
{
	int s;
	int ans,n;
	while(scanf("%d",&n)!=EOF)
	{
		s=1;
		ans=1;
		s%=n;
		while(s)
		{
			s=s*10+1;
			ans++;
			s%=n;
		}
		printf("%d\n",ans);
	}
	return 0;
}