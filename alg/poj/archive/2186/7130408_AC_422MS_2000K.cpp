#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
struct Edge
{
	int v;
	struct Edge*next;
}edge[50006];

int stack[50006],top,cnt,index,instack[50006],vis[50006];
int DFN[50006],Low[50006],s[50006];
int ans;
int tt;
set<int>Set;

void tarjan(int& i)
{
	if(tt>1)
	{
		ans=0;
		return;
	}
	struct Edge*p,*q;
	int j,k,l,flag;
	DFN[i]=Low[i]=++index;
	stack[++top]=i;
	instack[i]=1;
	for(p=edge[i].next;p!=NULL;p=p->next)
	{
		j=p->v;
		if(!DFN[j])
		{
			tarjan(j);
			if(Low[j]<Low[i])
			{
				Low[i]=Low[j];
			}
		}
		else if(instack[j]&&DFN[j]<Low[i])
		{
			Low[i]=DFN[j];
		}
	}
	if(DFN[i]==Low[i])
	{
		cnt++;
		int sum=0;
		Set.clear();
		do{
			j=stack[top--];
			Set.insert(j);
			instack[j]=0;
		}while(j!=i);
		flag=1;
		set<int>::iterator it;
		for(it=Set.begin();it!=Set.end();it++)
		{
			j=*it;
			for(p=edge[j].next;p!=NULL;p=p->next)
			{
				if(Set.find(p->v)==Set.end())
				{
					flag=0;
					break;
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(flag)
		{
			tt++;
			if(tt>1)
			{
				ans=0;
				return;
			}
			ans+=Set.size();
		}
	}
}

void ff()
{
	top=cnt=index=0;
	memset(DFN,0,sizeof(DFN));
	int i;
	memset(instack,0,sizeof(instack));
	for(i=1;i<=n;i++)
	{
		if(!DFN[i])
		{
			tarjan(i);
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m;
	struct Edge*p,*q;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		edge[i].next=NULL;
	}
	while(m--)
	{
		scanf("%d%d",&j,&i);
		p=&edge[j];
		while(p->next!=NULL)p=p->next;
		q=new struct Edge;
		q->v=i;
		q->next=NULL;
		p->next=q;
	}
	tt=0;
	ans=0;
	ff();
	printf("%d\n",ans);
	return 0;
}