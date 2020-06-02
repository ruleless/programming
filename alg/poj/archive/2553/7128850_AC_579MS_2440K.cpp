#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Edge
{
    int v;
    struct Edge* next;
}*p,*q,edge[5006];

int n;
int DFN[5006],deg[5006],belong[5006],stack[5006],top,index,cnt,Low[5006],instack[5006],res[5006];
set<int>Set;
set<int>::iterator it;

void tarjan(int k)
{
	struct Edge* pp;
    DFN[k]=Low[k]=++index;
	//printf("%d %d\n",k,DFN[k]);
    stack[++top]=k;
    instack[k]=1;
    int i,j,x;
    for(pp=edge[k].next;pp!=NULL;pp=pp->next)
    {
        j=pp->v;
        if(!DFN[j])
        {
            tarjan(j);
            if(Low[j]<Low[k])
            {
                Low[k]=Low[j];
            }
        }
        else if(instack[j]&&DFN[j]<Low[k])
        {
            Low[k]=DFN[j];
        }
    }
    if(DFN[k]==Low[k])
    {
		Set.clear();
        cnt++;
        do{
            j=stack[top--];
            instack[j]=0;
            belong[j]=cnt;
			Set.insert(j);
        }while(j!=k);
		int flag=1;
		for(it=Set.begin();it!=Set.end();it++)
		{
			j=*it;
			for(pp=edge[j].next;pp!=NULL;pp=pp->next)
			{
				i=pp->v;
				if(Set.find(i)==Set.end())
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
			{
				break;
			}
		}
		if(flag)
		{
			for(it=Set.begin();it!=Set.end();it++)
			{
				j=*it;
				res[j]=1;
			}
		}
    }
}

void f()
{
    memset(DFN,0,sizeof(DFN));
	memset(instack,0,sizeof(instack));
    top=cnt=index=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(!DFN[i])
        {
            tarjan(i);
        }
    }
}

int main(int argc, char *argv[])
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,e;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&e);
        for(i=1;i<=n;i++)
        {
            edge[i].next=NULL;
        }
        while(e--)
        {
            scanf("%d%d",&i,&j);
            p=&edge[i];
            while(p->next!=NULL)
            {
                p=p->next;
            }
            q=new struct Edge;
            q->v=j;
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
		memset(res,0,sizeof(res));
        f();
		
		for(k=n;k>=1&&res[k]==0;k--);
		for(i=1;i<k;i++)
		{
			if(res[i])
			{
				printf("%d ",i);
			}
		}
		if(k<1)
		{
			printf("\n");
		}
		else 
		{
			printf("%d\n",k);
		}
    }
    return EXIT_SUCCESS;
}
