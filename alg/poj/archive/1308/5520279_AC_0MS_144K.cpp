#include<iostream>
using namespace std;

static int up[10000],down[10000];

bool f(int*up,int*down,int i,int m)
{
	int j,k,cnt=m;
	for(j=0;j<i;j++)
		for(k=j+1;k<i;k++)
			if(down[j]==down[k])
				return false;
	for(j=0;j<m;j++)
		for(k=0;k<i;k++)
			if(up[j]==down[k])
			{
				cnt--;continue;
			}
	//printf("%d\n",cnt);
	if(cnt==1)
		return true;
	return false;
}

bool f1(int*up,int i,int a)
{
	int j;
	for(j=0;j<i;j++)
		if(up[j]==a)
			return false;
	return true;
}
		
int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,i,j,flag,c,d,k=0;
	scanf("%d%d",&a,&b);
	while(a!=-1&&b!=-1)
	{
		k++;
		i=0;j=0;flag=0;
		while(a!=0&&b!=0)
		{
			//printf("%d %d\n",a,b);
			if(a==d&&b==c)
				flag=1;
			c=a;d=b;
			if(f1(up,i,a))
			{
				up[i]=a;i++;
			}
			down[j]=b;j++;
			scanf("%d%d",&a,&b);
		}
		//printf("%d\n",i);
		if(flag==1)
		{
			printf("Case %d is not a tree.\n",k);
			goto lop;
		}
		if(i==0&&j==0)
			printf("Case %d is a tree.\n",k);			
		else if(f(up,down,j,i))
			printf("Case %d is a tree.\n",k);
		else
			printf("Case %d is not a tree.\n",k);
lop: scanf("%d%d",&a,&b);
	}
	return 0;
}
