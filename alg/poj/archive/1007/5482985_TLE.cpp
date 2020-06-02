#include<iostream>
#include<cstring>
using namespace std;

int count(char*p)
{
	int cnt=0,i,j;
	for(i=0;i<=strlen(p)-2;i++)
		for(j=i+1;j<=strlen(p)-1;j++)
			if(p[i]>p[j])
				cnt++;
	return cnt;
}


int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;char str[100][51];char c[51];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",str[i]);
	}
	for(i=0;i<m;i++)
		for(j=i+1;j<m;j++)
			if(count(str[j])<count(str[i]))
			{
				strcpy(c,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],c);
			}
	for(i=0;i<m;i++)
		printf("%s\n",str[i]);
	return 0;
}