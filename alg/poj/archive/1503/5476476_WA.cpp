#include<iostream>
#include<cstring>
using namespace std;

void nz(char*p)
{
	int n=strlen(p);
	char c;
	for(int i=0;i<=(n-1)/2;i++)
	{
		c=p[i];p[i]=p[n-1-i];p[n-1-i]=c;
	}
}

void add(char*sum,char*num)
{
	char sum1[103];int i,j,c=0;
	for(i=strlen(sum);i<103;i++)
		sum[i]='0';
	for(i=strlen(num);i<103;i++)
		num[i]='0';
	for(i=0;i<=100;i++)
	{
		sum1[i]=char(int(sum[i]+num[i]-96+c)%10+48);
		c=int(sum[i]+num[i]-96)/10;
	}
	sum1[101]=char(int(sum[101]+num[101]-96+c)%10+48);
	for(j=101;j>=0&&sum1[j]=='0';j--);
	sum1[j+1]='\0';
	strcpy(sum,sum1);
}



int main()
{
	char num[103],sum[103]={'\0'};
	//freopen("in.txt","r",stdin);
	scanf("%s",num);//printf("%s",num);
	while(strcmp(num,"0")!=0)
	{
		//printf("%s\n",num);
		nz(num);//printf("%s\n",num);
		add(sum,num);//printf("%s\n",sum);
		scanf("%s",num);
	}
	//printf("%d",strlen(sum));
	nz(sum);
	printf("%s\n",sum);
	return 0;
}
