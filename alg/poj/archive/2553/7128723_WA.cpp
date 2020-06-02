#include <cstdlib>
#include <iostream>

using namespace std;

struct Edge
{
    int v;
    struct Edge* next;
}*p,*q,edge[5006];

int n;
int DFN[5006],deg[5006],belong[5006],stack[5006],top,index,cnt,Low[5006],instack[5006],res[5006];
int temp[5006],z[5006];


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
        cnt++;
		x=0;
		int sum=0;
        do{
			sum++;
            j=stack[top--];
            instack[j]=0;
            belong[j]=cnt;
			temp[x++]=j;
        }while(j!=k);
		for(i=0;i<x;i++)
		{
			z[temp[i]]=sum;
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

void dd()
{
	int i,j;
	memset(deg,0,sizeof(deg));
	struct Edge* pp;
	for(i=1;i<=n;i++)
	{
		for(pp=edge[i].next;pp!=NULL;pp=pp->next)
		{
			deg[i]++;
		}
	}
}

int main(int argc, char *argv[])
{
//    freopen("in.txt","r",stdin);
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
        f();
		dd();
		memset(res,0,sizeof(res));
		for(i=1;i<=n;i++)
		{
			if(deg[i]==0||z[i]>1)
			{
				res[i]=1;
			}
		}
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
        //printf("%d\n",cnt);
        /*for(i=1;i<=n;i++)
        {
            printf("%d\n",belong[i]);
        }*/
    }
    return EXIT_SUCCESS;
}
