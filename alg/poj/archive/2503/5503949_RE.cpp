#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	char eng[11],fo[11];
};

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
	node dic[100000],*q;
	char c,mes[11];
	int i=0;
	while(1)
	{
		scanf("%s%s",dic[i].eng,dic[i].fo);
		getchar();
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
