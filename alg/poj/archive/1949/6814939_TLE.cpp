#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int vex;
	struct Node* next;
}*p;

struct Node table[10006];
int n,deg[10006],res;

bool include(int i,int k)
{
	struct Node* q=table[i].next;
	while(q!=NULL)
	{
		if(q->vex==k)
			return true;
		q=q->next;
	}
	return false;
}

void topsort()
{
	int i,j;
	memset(deg,0,sizeof(deg));
	for(i=1;i<=n;i++)
	{
		p=table[i].next;
		int cnt=0;
		while(p!=NULL)
		{
			
			cnt++;
			p=p->next;
		}
		deg[i]=cnt;
	}
	printf("%d\n",deg[1]);
	stack<int> sta;
	sta.push(1);
	int count=0;
	while(!sta.empty())
	{
		i=sta.top();
		sta.pop();
		count++;
		if(count!=n)
			res+=table[i].vex;
		for(j=1;j<=n;j++)
		{
			if(include(j,i))
			{
				deg[j]--;
				if(deg[j]==0)
					sta.push(j);
			}
		}
	}
//	printf("%d\n",count);
}

void work()
{
	int i,j,k;
	memset(deg,0,sizeof(deg));
	for(i=1;i<=n;i++)
	{
		p=table[i].next;
		int cnt=0;
		while(p!=NULL)
		{
			
			cnt++;
			p=p->next;
		}
		deg[i]=cnt;
	}
	for(i=1;i<=n;i++)
	{
		k=table[i].vex;
		res+=k;
		if(k==0)
		{
			continue;
		}
		for(j=1;j<=n;j++)
		{
			if(deg[j]==0&&table[j].vex!=0)
			{
				if(table[j].vex>k)
				{
					table[j].vex-=k;
				}
				else 
				{
					table[j].vex=0;
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			if(deg[j]!=0&&include(j,i))
			{
				deg[j]--;
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	res=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		table[i].next=NULL;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&table[i].vex);
		scanf("%d",&j);
		p=&table[i];
		while(j--)
		{
			
			scanf("%d",&k);
			p->next=new struct Node;
			p=p->next;
			p->next=NULL;
			p->vex=k;
		}
	}
	work();
	printf("%d\n",res);
	return 0;
}