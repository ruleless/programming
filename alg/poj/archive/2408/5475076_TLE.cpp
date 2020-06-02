#include<iostream>
#include<cstring>
using namespace std;

int strcmp1(char*p,char*q)
{
	if(strlen(p)!=strlen(q))
		return 0;
	int i,j;
	int *flag,n=strlen(q);
	flag=new int[n];
	for(i=0;i<n;i++)
		flag[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(flag[j]==0&&p[i]==q[j])
				flag[j]=1;
	for(i=0;i<n&&flag[i]==1;i++);
	if(i==n)
		return 1;
	else return 0;
}

int main()
{
	char word[30001][20],temp[20];int cnt=0;int flag[30001]={0},count[30001]={1},i,j,k,t,t1;
	//freopen("in.txt","r",stdin);
	while(scanf("%s",word[cnt])!=EOF)	
		cnt++;
	for(i=0;i<cnt;i++)
		count[i]=1;
	for(i=0;i<cnt-1;i++)
		if(flag[i]==0)
		{
		for(j=i+1;j<cnt;j++)
			if(flag[j]==0)
			{
		    	if(strcmp1(word[i],word[j])==1)
				{
		    		count[i]++;
		    		flag[j]=1;
				}
			}
		}
	//for(i=0;i<cnt;i++)
		//printf("%s %d %d\n",word[i],flag[i],count[i]);
	for(i=0;i<cnt;i++)
		if(flag[i]==0)
		{
			for(k=i;k<cnt;k++)
			{
			if(strcmp1(word[k],word[i])==1)
			for(j=k+1;j<cnt;j++)
				if(strcmp1(word[k],word[j])==1)
				{
					if(strcmp(word[j],word[k])==-1)
					{
						strcpy(temp,word[k]);
						strcpy(word[k],word[j]);
						strcpy(word[j],temp);
					}
				}
			}
		}
	//for(i=0;i<cnt;i++)
		//printf("%s\n",word[i]);
	for(i=1;i<6;i++)
	{
		for(j=0;j<cnt&&flag[j]==1;j++);
		t=j;
		if(t==cnt)
			break;
		
		for(j=t+1;j<cnt;j++)
		{
			if(flag[j]==0)
			if(count[j]>count[t])t=j;
			else if(count[j]==count[t])
			{
				if(strcmp(word[j],word[t])==-1)
					t=j;
			}
		}
		flag[t]=1;
		printf("Group of size %d: ",count[t]);t1=t;printf("%s ",word[t]);
		for(j=t+1;j<cnt;j++)
			if(strcmp1(word[j],word[t])==1&&strcmp(word[j],word[t1])!=0)
			{
				t1=j;
				printf("%s ",word[j]);
			}
		printf(".\n");
	}
	return 0;
}