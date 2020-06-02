#include<iostream>
#include<cstring>
using namespace std;


void mul(int*&ad,int& adc,int*&f,int& fc,int*&g,int& gc)
{
	adc=fc+gc-1;
	ad=new int[adc];
	int i,j;
	for(i=0;i<adc;i++)
		ad[i]=0;
	for(i=0;i<fc;i++)
		for(j=0;j<gc;j++)
		{
			ad[adc-fc-gc+i+j+1]=(ad[adc-fc-gc+i+j+1]+f[i]*g[j])%2;
		}
	//for(i=0;i<adc;i++)
		//printf("%d ",ad[i]);
}

void sub(int*&ad,int& adc,int*&f,int& fc,int*&h,int& hc)
{
	int*ad1;int adc1,i,j;
	adc1=(fc>hc)?fc:hc;int expf=fc-1,exph=hc-1;
	ad1=new int[adc1];
	for(i=0;i<adc1;i++)
	{
		if(adc1-i-1==expf&&adc1-i-1==exph)
		{
			ad1[i]=abs(f[i]-h[i])%2;
			expf--;exph--;
		}
		else if(adc1-i-1==expf)
		{
			ad1[i]=f[i];expf--;
		}
		else if(adc1-i-1==exph)
		{
			ad1[i]=h[i];
			exph--;
		}
	}
	for(i=0;i<adc1&&ad1[i]==0;i++);
	adc=adc1-i;
	ad=new int[adc];
	for(j=i;j<adc1;j++)
		ad[j-i]=ad1[j];
	delete []ad1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t,fc,gc,hc,adc,i,j,adc1,tempc1;
	int*f,*g,*h,*ad,*ad1,*temp1;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&fc);f=new int[fc];
		for(j=0;j<fc;j++)
		{
			scanf("%d",&f[j]);//printf("%d ",f[j]);
		}
		//putchar('\n');
		scanf("%d",&gc);g=new int[gc];
		for(j=0;j<gc;j++)
		{
			scanf("%d",&g[j]);//printf("%d ",g[j]);
		}
		//putchar('\n');
		scanf("%d",&hc);h=new int[hc];
		for(j=0;j<hc;j++)
		{
			scanf("%d",&h[j]);//printf("%d ",h[j]);
		}
		//putchar('\n');
		mul(ad,adc,f,fc,g,gc);//putchar('\n');
		//printf("%d ",adc);
		//for(j=0;j<adc;j++)
			//printf("%d ",ad[0]);
		while(adc>=hc)
		{
			adc1=adc;
			ad1=new int[adc1];
			for(j=0;j<adc1;j++)
				ad1[j]=ad[j];
			tempc1=adc;
			temp1=new int[tempc1];
			for(j=0;j<hc;j++)
				temp1[j]=h[j];
			for(j=hc;j<adc;j++)
				temp1[j]=0;
			//for(j=0;j<tempc1;j++)
			//{
			//	printf("%d ",temp1[j]);
			//}
			sub(ad,adc,ad1,adc1,temp1,tempc1);delete[]temp1;delete[]ad1;
		}
		printf("%d ",adc);
		for(j=0;j<adc;j++)
			printf("%d ",ad[j]);
		putchar('\n');
		delete []f;delete[]g;delete[]h;delete[]ad;
	}
	return 0;
}