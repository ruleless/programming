#include<iostream>
using namespace std;

int hash[3012501+1];
int a[500000+1];

int main()
{
//	freopen("in.txt","r",stdin);
	int k,i;
	a[0]=0;hash[0]=0;
	while(scanf("%d",&k),k!=-1)
	{
		memset(hash,-1,sizeof(int)*3012502);
		for(i=1;i<=k;i++)
		{
	    	if(a[i-1]-i>0&&hash[a[i-1]-i]==-1)
			{
	    		a[i]=a[i-1]-i;hash[a[i]]=0;
			}
	    	else
			{
		    	a[i]=a[i-1]+i;hash[a[i]]=0;
			}
		}	
		printf("%d\n",a[k]);
	}
	return 0;
}
		