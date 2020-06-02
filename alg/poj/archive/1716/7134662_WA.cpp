#include <cstdlib>
#include <iostream>

using namespace std;

struct Edge
{
    int u;
    struct Edge* next;
}edge[10005];
int n,Min,Max;
int dist[10005],q[10005],inque[10005];
#define MAX 100000000

int spfa()
{
    struct Edge*p;
    int i,j,k,head,tail;
    head=tail=0;
    for(i=Min+1;i<=Max;i++)
    {
        dist[i]=-MAX;
    }
    dist[Min]=0;
    q[tail++]=Min;
    memset(inque,0,sizeof(inque));
    inque[Min]=1;
    while(head<tail)
    {
        k=q[head++];
        inque[k]=0;
        for(p=edge[k].next;p!=NULL;p=p->next)
        {
            if(dist[k]+2>dist[p->u])
            {
                dist[p->u]=dist[k]+2;
                if(!inque[p->u])
                {
                     for(i=Min;i<Max;i++)
        {
            if(dist[i+1]<dist[i])
            {
                dist[i+1]=dist[i];
            }
        }
        for(i=Max;i>Min;i--)
        {
            if(dist[i]>dist[i-1]+1)
            {
                dist[i-1]=dist[i]-1;
            }
        }
                    inque[p->u]=1;
                    q[tail++]=p->u;
                }
            }
        }
        /*for(i=Min;i<Max;i++)
        {
            if(dist[i+1]<dist[i])
            {
                dist[i+1]=dist[i];
            }
        }
        for(i=Max;i>Min;i--)
        {
            if(dist[i]>dist[i-1]+1)
            {
                dist[i-1]=dist[i]-1;
            }
        }*/
    }
    return dist[Max];
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    struct Edge*p,*q;
    scanf("%d",&n);
    Min=1<<30;
    Max=0;
    while(n--)
    {
        scanf("%d%d",&i,&j);
        j++;
        if(i<Min)
        {
            Min=i;
        }
        if(j>Max)
        {
            Max=j;
        }
        p=&edge[i];
        while(p->next!=NULL)p=p->next;
        q=new struct Edge;
        q->u=j;
        q->next=NULL;
        p->next=q;
    }
    printf("%d\n",spfa());
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
