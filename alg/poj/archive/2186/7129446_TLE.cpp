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
}edge[50006],e[50006];

int stack[50006],top,cnt,index,instack[50006],visited[50006];
int DFN[50006],Low[50006],s[50006];
vector<int> vec[50006];
int ans;

void tarjan(int i)
{
	struct Edge*p,*q;
	int j,k,l;
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
		do{
			j=stack[top--];
			instack[j]=0;
			vec[cnt].push_back(j);
		}while(j!=i);
		s[cnt]=vec[cnt].size();
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
set<int>Set;

bool has(int i,int j)
{
	struct Edge*p,*q;
	Set.clear();
	int k,l;
	for(k=0;k<vec[j].size();k++)
	{
		Set.insert(vec[j][k]);
	}
/*	set<int>::iterator it;
	for(it=Set.begin();it!=Set.end();it++)
	{
		printf("s%d ",*it);
	}*/
	for(k=0;k<vec[i].size();k++)
	{
		for(p=edge[vec[i][k]].next;p!=NULL;p=p->next)
		{
			if(Set.find(p->v)!=Set.end())
			{
				//printf("%d",p->v);
				return true;
			}
		}
	}
	return false;
}

void dfs(int i)
{
	int j;
	struct Edge*p;
	for(p=e[i].next;p!=NULL;p=p->next)
	{
		if(!visited[p->v])
		{
			visited[p->v]=1;
			dfs(p->v);
		}
	}
}

void solve()
{
	int i,j,k;
	struct Edge*p,*q;
	for(i=1;i<=cnt;i++)
	{
		e[i].next=NULL;
	}
	for(i=1;i<=cnt;i++)
	{
		for(j=1;j<=cnt;j++)
		{
			if(i!=j)
			{
				if(has(i,j))
				{
					p=&e[i];
					while(p->next!=NULL)p=p->next;
					q=new struct Edge;
					q->next=NULL;
					q->v=j;
					p->next=q;
				}
			}
		}
	}
	for(i=1;i<=cnt;i++)
	{
		memset(visited,0,sizeof(visited));
		visited[i]=1;
		dfs(i);
		for(j=1;j<=cnt;j++)
		{
			if(visited[j]==0)
			{
				break;
			}
		}
		if(j>cnt)
		{
			ans+=s[i];
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
		scanf("%d%d",&i,&j);
		p=&edge[j];
		while(p->next!=NULL)p=p->next;
		q=new struct Edge;
		q->v=i;
		q->next=NULL;
		p->next=q;
	}
	/*for(i=1;i<=n;i++)
	{
		printf("%d: ",i);
		for(p=edge[i].next;p!=NULL;p=p->next)
		{
			printf("%d ",p->v);
		}
		printf("\n");
	}*/
	ans=0;
	ff();
	solve();
/*	for(i=1;i<=n;i++)
	{
		printf("%d: ",i);
		for(p=edge[i].next;p!=NULL;p=p->next)
		{
			printf("%d ",p->v);
		}
		printf("\n");
	}*/
	printf("%d\n",ans);
	return 0;
}