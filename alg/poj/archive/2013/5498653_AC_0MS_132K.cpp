#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int t,i,cnt=1,j;char name[16][26],c[26];
	while(scanf("%d",&t),t)
	{
		for(i=0;i<t;i++)
		{
			scanf("%s",name[i]);
			//printf("%s\n",name[i]);
		}
		printf("SET %d\n",cnt);cnt++;
		for(i=0;i<t;i+=2)
			printf("%s\n",name[i]);
		if(t%2==0)
			i=t-1;
		else
			i=t-2;
		for(j=i;j>=0;j-=2)
			printf("%s\n",name[j]);
	}
	return 0;
}