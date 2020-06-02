#include<iostream>
using namespace std;

int B,P,p,b,n;
float res;

struct node{
	int B,P;
}man[100][100];

int count[100];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		b=999999999;
		p=0;
		for(i=0;i<n;i++)
		{
			res=0;
			scanf("%d",&count[i]);
			for(j=0;j<count[i];j++)
			{
				scanf("%d%d",&man[i][j].B,&man[i][j].P);
				if(man[i][j].B*1.0/man[i][j].P>res)
				{
					res=man[i][j].B*1.0/man[i][j].P;
					P=man[i][j].P;
					B=man[i][j].B;
				}
			}
			b=(b<B)?b:B;
			p+=P;
		}
		printf("%.3f\n",b*1.0/p);
	}
	return 0;
}