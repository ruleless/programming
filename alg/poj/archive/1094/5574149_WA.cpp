#include<iostream>
#include<stack>
using namespace std;

int indegree[27];
struct node{
	int vex;struct node *next;
};

struct node* V[27];


int main()
{
	freopen("in.txt","r",stdin);
	int n,m,i,v;
	struct node*p,*q;
	stack<int>sta;
	char str[4];
	while(scanf("%d%d",&n,&m),n!=0&&m!=0)
	{
		memset(indegree,0,sizeof(indegree));
		for(i=0;i<n;i++)
			V[i]=NULL;
		for(i=1;i<=m;i++)
		{
			scanf("%s",str);
			p=new struct node;
			p->next=NULL;
			p->vex=int(str[2]-'A');
			q=V[str[0]-'A'];
			while(q!=NULL)q=q->next;
			q=p;
			indegree[str[2]-'A']+=1;
		}
		for(i=0;i<n;i++)
			if(indegree[i]==0)
				sta.push(i);
		while(!sta.empty())
		{
			v=sta.top();
			sta.pop();
			printf("%c\n",v+'A');
			p=V[v];
			while(p!=NULL)
			{
				p=p->next;
				if((--indegree[p->vex])==0)
					sta.push(p->vex);
			}
		}
	}
	return 0;
}
