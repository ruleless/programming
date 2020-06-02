#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	int score;char name[30];
};

int cmp(const void*p,const void*q)
{
	return strcmp(((node*)p)->name,((node*)q)->name);
}


int main()
{
	//freopen("in.txt","r",stdin);
	int m,n,i,j,k,sc,rank,score[10000]={0};
	char name[10000][31];node temp[10000];
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
			scanf("%d",&temp[j].score);getchar();
			gets(temp[j].name);
		}
		qsort(temp,m,sizeof(node),cmp);
		for(j=0;j<m;j++)
			score[j]+=temp[j].score;
		for(j=0;j<m&&strcmp(temp[j].name,"Li Ming")!=0;j++);
		for(k=0;k<m;k++)
			if(score[k]>score[j])
				rank++;
		printf("%d\n",rank);

	}
	return 0;
}