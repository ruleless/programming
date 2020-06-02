#include<iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;

stack<char>sta[25];
bool flag[28];

int main()
{
//	freopen("in.txt","r",stdin);
	int sum,i,n,j,k,m;
	char str[200];
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(flag,0,sizeof(flag));
		for(j=1;j<=n;j++)
		{
			while(!sta[j].empty())
				sta[j].pop();
		}
		scanf("%s",str);
		m=strlen(str);
		sum=0;
		for(i=0;i<m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(sta[j].empty())
				{
					sta[j].push(str[i]);
					break;
				}
				else if(sta[j].top()==str[i])
				{
					sta[j].pop();
					break;
				}
			}
			if(j==n+1)
				sum++;
		}
		if(sum==0)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n",sum/2);
	}
	return 0;
}