#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	int Q_num,period;
};
node data[1050];


int temp[1050];

int cmp1(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int cmp(const void*a,const void*b)
{
	return ((node*)a)->period-((node*)b)->period;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int N=0,n,i,cnt=0,j=0,m,k;
	char str[25];
	while(scanf("%s",str),strcmp(str,"#")!=0)
	{
		scanf("%d%d",&data[N].Q_num,&data[N].period);
		N++;
	}
	qsort(data,N,sizeof(node),cmp);
	scanf("%d",&n);
	for(i=data[0].period;cnt!=n;i++)
	{
		if(i%data[j].period==0)
		{
			k=0;
			temp[k]=data[j].Q_num;
			k++;cnt++;
			if(cnt==n)
				goto loop;
			else
			for(m=j-1;m>=0;m--)
			{
				if(i%data[m].period==0)
				{
					temp[k]=data[m].Q_num;
					k++;cnt++;
					if(cnt==n)
						break;
				}
			}
        	qsort(temp,k,sizeof(int),cmp1);
loop:   	for(m=0;m<k;m++)
				printf("%d\n",temp[m]);
			j=(j+1)%N;
		}
		//printf("%d %d\n",cnt,j);
	}
	return 0;
}
