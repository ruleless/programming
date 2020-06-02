#pragma warning(disable:4786)
#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	map<char,int> Map;
	map<int,char> Map0;
	char ss[15];
	int s[15],tmp;
	int n,i,j,m;
	scanf("%d",&n);
	for(i=0;i<26;i++)
	{
		Map[char(int('A')+i)]=1+2*i;
		Map[char(int('a')+i)]=2+2*i;
		Map0[1+2*i]=char(int('A')+i);
		Map0[2+2*i]=char(int('a')+i);
	}
	while(n--)
	{
		scanf("%s",ss);
		m=strlen(ss);
		for(i=0;i<m;i++)
			s[i]=Map[ss[i]];
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++)
				if(s[i]>s[j])
				{
					tmp=s[i];
					s[i]=s[j];
					s[j]=tmp;
				}
		do
		{
			for(i=0;i<m;i++)
				ss[i]=Map0[s[i]];
			printf("%s\n",ss);
		}while(next_permutation(s,s+m));
	}
	return 0;
}