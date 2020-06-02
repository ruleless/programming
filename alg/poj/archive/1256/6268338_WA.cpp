#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char s[15],tmp;
	int n,i,j,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		m=strlen(s);
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++)
				if(s[j]<s[i])
				{
					tmp=s[i];
					s[i]=s[j];
					s[j]=tmp;
				}
		do
		{
			printf("%s\n",s);
		}while(next_permutation(s,s+m));
	}
}