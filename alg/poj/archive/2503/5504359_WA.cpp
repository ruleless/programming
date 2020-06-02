#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

struct node
{
	char eng[12],fo[12];
};
node dic[100002];

int cmp(const void*p,const void*q)
{
	return strcmp(((node*)p)->fo,((node*)q)->fo);
}

int cmp1(const void*p,const void*q)
{
	return strcmp((char*)p,((node*)q)->fo);
}

int main()
{
	//freopen("in.txt","r",stdin);
	node *q;
	char c,mes[12];
	int i=0;
	while(1)
	{
		scanf("%s%s",dic[i].eng,dic[i].fo);
		while((c=getchar())!='\n');
		//printf("%s %s\n",dic[i].eng,dic[i].fo);
		if((c=getchar())=='\n')
			break;
		else
			fseek(stdin,-1,1);
		i++;
	}
	i++;
	//printf("%d",i);
	qsort(dic,i,sizeof(node),cmp);
	while(scanf("%s",mes)!=EOF)
	{
		q=(node*)bsearch(mes,dic,i,sizeof(node),cmp1);
		if(q==NULL)
			printf("eh\n");
		else
			printf("%s\n",q->eng);
	}
	return 0;
}
