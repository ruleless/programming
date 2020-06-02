#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char s[150];
	int num[6],i,j,t;
	float x;
	while(scanf("%d%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5]),!(num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0))
	{
		for(i=0;i<6;i++)
			for(j=i+1;j<6;j++)
				if(num[j]>num[i])
				{
					t=num[i];
					num[i]=num[j];
					num[j]=t;
				}
		t=0;
		for(i=1;i<5;i++)
			t+=num[i];
		x=1.0*t/4;
		printf("%g\n",x);
	/*	sprintf(s,"%.80f",x);
		j=strlen(s);
		
		for(i=j-1;i>=0&&(s[i]=='0'||s[i]=='.');i--);
	//	printf("%d\n",i);
		s[i+1]='\0';
		printf("%s\n",s);*/
	}
	return 0;
}
		
			