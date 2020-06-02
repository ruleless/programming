#include<iostream>
#include<stack>
using namespace std;

int a[22],b[22],c[22];

struct node
{
	int num;
	char c;
}temp;

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,cnt;
	stack<struct node>sta;
	stack<struct node>sta1;
	stack<struct node>sta2;
	scanf("%d",&t);
	while(t--)
	{
		a[0]=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		cnt=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=a[i]-a[i-1];j++)
			{
				temp.c='(';
				temp.num=cnt;
				cnt++;
				sta.push(temp);
			}
			temp.c=')';
			temp.num=i;
			sta.push(temp);
		}
		cnt=1;
		memset(c,0,sizeof(c));
		while(!sta.empty())
		{
			if(sta.top().c==')')
			{				
				sta1.push(sta.top());
				sta.pop();
			}
			else
			{
				b[sta1.top().num]=c[sta1.top().num]+1;
				sta1.pop();
				while(!sta1.empty())
				{
					sta2.push(sta1.top());
					c[sta1.top().num]++;
					sta1.pop();
				}
				while(!sta2.empty())
				{
					sta1.push(sta2.top());
					sta2.pop();
				}
				sta.pop();
			}
		}
		for(i=1;i<n;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}