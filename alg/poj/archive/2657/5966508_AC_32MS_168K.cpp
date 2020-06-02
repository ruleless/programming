#include<iostream>
using namespace std;

bool a[1002];
bool flag[10002];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,z,m,k,i,j;
	scanf("%d%d%d",&n,&z,&m);
	memset(a,0,sizeof(a));
	while(m--)
	{
		scanf("%d",&i);
		a[i-1]=true;
	}
	for(k=1;;k++)
	{
		memset(flag,0,sizeof(flag));
		for(i=0;;i=(k+i)%n)
		{
			if(a[i]==true)
				break;
			else if(i==z-1)
			{
			//	printf("%d\n",k);
				break;
			}
			else if(flag[i]==true)
				break;
			flag[i]=true;
		}
		if(i==z-1)
			break;
	}
	printf("%d\n",k);
	return 0;
}