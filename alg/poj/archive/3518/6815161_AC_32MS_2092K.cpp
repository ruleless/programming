#include<iostream>
using namespace std;

#define N 2000000

bool isprim[N+1];

void prim()
{
	int i,j;
    for (i=0;i<=N;i++)
        isprim[i]=true;
    isprim[0]=false;
    isprim[1]=false;
    for (i=2;i<=N;i++)
        if (isprim[i])
            for (j=2;i*j<=N;j++)
                    isprim[i*j]=false;
}


int main()
{
	int x,i,j;
	prim();
	while(scanf("%d",&x)&&x)
	{
		if(isprim[x])
			printf("0\n");
		else
		{
			for(i=x-1;!isprim[i];i--);
			for(j=x+1;!isprim[j];j++);
			printf("%d\n",j-i);
		}
	}
	return 0;
}