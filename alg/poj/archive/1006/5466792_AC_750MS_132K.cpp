#include<iostream>
using namespace std;

struct node
{
	int day;
	int lenth;
};


int main()
{
	//freopen("in.txt","r",stdin);
	int j,k,n=0,p,e,i,d,g;
	scanf("%d",&p);
	scanf("%d",&e);
	scanf("%d",&i);
	scanf("%d",&d);
	while(p!=-1)
	{
		n++;//printf("%d ",p);printf("%d ",e);printf("%d ",i);printf("%d\n",d);
		g=1;
		while(!((g+d-p)%23==0&&(g+d-e)%28==0&&(g+d-i)%33==0))
			g++;

		printf("Case %d: the next triple peak occurs in %d days.\n",n,g);
		scanf("%d",&p);
    	scanf("%d",&e);
    	scanf("%d",&i);
    	scanf("%d",&d);
	}
	return 0;
}

					
