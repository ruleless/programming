#include<iostream>
#include<string>
#include<cstring>

char s1[1002],s2[4002],temp[10];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s1);
		n=strlen(s1);
		strcpy(s2,"");
		for(i=0;i<n;)
		{
			for(j=i+1;j<n&&s1[i]==s1[j];j++);
			sprintf(temp,"%d",j-i);
			strcat(s2,temp);
			temp[0]=s1[i];
			temp[1]='\0';
			strcat(s2,temp);
			i=j;
		}
		printf("%s\n",s2);
	}
	return 0;
}