#include<iostream>
#include<cstring>
using namespace std;

char s[100001],t[100001];

int main()
{
//	freopen("in.txt","r",stdin);
	int m,n,i,j;
	while(scanf("%s%s",s,t)==2)
	{
		m=strlen(s);
		n=strlen(t);
		j=0;
		for(i=0;i<m;i++)
		{
			while(j<n)
			{
				if(s[i]==t[j])
				{
					j++;
					break;
					
				}
				else
					j++;
			}
			if(j==n)
				break;
		}
		if(i==m)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
