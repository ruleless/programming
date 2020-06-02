#include<iostream>
using namespace std;

void ff(int*&temp,int&tc,int *Q,int n)
{
	int i,j,*temp1;
	temp1=new int[tc+n+1];
	for(i=0;i<=tc+n;i++)
		temp1[i]=0;
	for(i=0;i<=tc;i++)
		for(j=0;j<=n;j++)
		{
			temp1[i+j]=temp1[i+j]+temp[i]*Q[j];
		}
	tc=n+tc;
	for(i=0;i<=tc;i++)
		temp[i]=temp1[i];
	delete[]temp1;
}


int main()
{
	freopen("in.txt","r",stdin);
	int i,t,j,*P,*Q,m,n,p,tc,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int*R,*temp;
		scanf("%d%d",&m,&n);
		P=new int[m+1];Q=new int[n+1];
		for(j=0;j<=m;j++)
		{
			scanf("%d",&P[j]);//printf("%d ",P[j]);
		}
		//putchar('\n');
		for(j=0;j<=n;j++)
		{
			scanf("%d",&Q[j]);//printf("%d ",Q[j]);
		}
		//putchar('\n');

		R=new int[m*n+1];
		temp=new int[m*n+1];
		R[0]=P[0];
		for(j=1;j<=m*n;j++)
		{
			temp[j]=0;
			R[j]=0;
		}
		temp[0]=0;
		for(j=0;j<=n;j++)
			temp[j]=Q[j];tc=n;
		//for(j=0;j<=tc;j++)
		//{
			//printf("%d ",temp[j]);
		//}
		//putchar('\n');
		for(j=1;j<=m;j++)
			if(P[j]!=0)
			{
				//int*temp;
				for(k=0;k<=tc;k++)
					R[k]+=temp[k]*P[j];
				//for(k=0;k<=tc;k++)
			//	{
		        	//printf("%d ",temp[k]);
				//}
		        //putchar('\n');
				if(j!=m)
				ff(temp,tc,Q,n);
				//delete[]temp;
			}
		for(k=0;k<=m*n-1;k++)
		{
			printf("%d ",R[k]);
		}
		printf("%d\n",R[m*n]);
		delete[]R;delete[]temp;
	}
	return 0;
}
