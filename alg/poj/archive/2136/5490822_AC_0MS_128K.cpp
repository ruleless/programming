#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int cnt[26]={0},i,max,j;
	char c;
	while((c=getchar())!=EOF)
	{
		if(c<='Z'&&c>='A')
			cnt[int(c-'A')]++;
	}
	//for(i=0;i<=25;i++)
		//printf("%d ",cnt[i]);
	max=cnt[0];
	for(i=1;i<=25;i++)
		if(cnt[i]>max)
			max=cnt[i];
	//printf("%d",max);
	for(i=max;i>=1;i--)
	{
		for(j=0;j<=25;j++)
			if(cnt[j]>=i)
				printf("* ");
			else
				printf("  ");
		putchar('\n');
	}
	for(i=0;i<=25;i++)
		printf("%c ",char(int('A')+i));
	return 0;
}