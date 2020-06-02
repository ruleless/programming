#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,ma,i,ii,jj,j,b,p,k,price,min;float max;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);int *band;
		band=new int[n];price=0;
		
		for(k=0;k<n;k++)
		{
			scanf("%d",&ma);
			max=0;
     		for(j=1;j<=ma;j++)
			{
	    		scanf("%d%d",&b,&p);
	    		if(1.0*b/p>max)
				{
		    		max=1.0*b/p;
			    	ii=b;jj=p;
				}
			}
			price+=jj;band[k]=ii;
		}
		min=band[0];
		for(j=1;j<n;j++)
			if(band[j]<min)
				min=band[j];
		max=1.0*min/price;
		printf("%.3f\n",max);
	}
	return 0;
}

 
