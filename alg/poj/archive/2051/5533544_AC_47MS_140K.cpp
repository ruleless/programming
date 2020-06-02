#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	int Q_num,period;
};
node data[1050];

int cmp(const void*a,const void*b)
{
	return ((node*)a)->Q_num-((node*)b)->Q_num;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int N=0,n,i,cnt=0,j=0;
	char str[25];
	while(scanf("%s",str),strcmp(str,"#")!=0)
	{
		scanf("%d%d",&data[N].Q_num,&data[N].period);
		N++;
	}
	qsort(data,N,sizeof(node),cmp);
	scanf("%d",&n);
	for(i=1;cnt!=n;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i%data[j].period==0)
			{
				printf("%d\n",data[j].Q_num);
				cnt++;
			}
		}
	}
	return 0;
}