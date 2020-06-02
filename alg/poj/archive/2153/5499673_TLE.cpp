#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int score[10000]={0},m,n,i,j,k,sc,rank;
	char name[10000][31],temp[31];
	scanf("%d",&m);getchar();
	for(i=0;gets(name[i]),i<m-1;i++);
	//for(i=0;i<m;i++)
		//printf("%s\n",name[i]);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		rank=1;
		for(j=0;j<m;j++)
		{
			scanf("%d",&sc);getchar();
			gets(temp);
			for(k=0;k<m&&strcmp(temp,name[k])!=0;k++);
			score[k]+=sc;
		}
		for(j=0;j<m&&strcmp(name[j],"Li Ming")!=0;j++);
		for(k=0;k<m;k++)
			if(score[k]>score[j])
				rank++;
		printf("%d\n",rank);

	}

	return 0;
}