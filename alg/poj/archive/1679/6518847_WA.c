#include <stdio.h>
#include <stdlib.h>

int n,m;
int parent[103];
int tmp[103];

int Find(int x)
{
    if(parent[x]<0)
    {
        return x;
    }
    int t=Find(parent[x]);
    parent[x]=t;
    return t;
}

void Union(int a,int b)
{
    int x=Find(a);
    int y=Find(b);
    parent[x]+=parent[y];
    parent[y]=x;
}

struct Node
{
    int x,y,w;
}edge[10003];

int cmp(const void*a,const void*b)
{
    struct Node *x=(struct Node*)a;
    struct Node *y=(struct Node*)b;
    return x->w-y->w;
}

int ff()
{
    int t=Find(1);
    int i;
    for(i=1;i<m;i++)
    {
        if(Find(i)!=t)
            return 0;
    }
    return 1;
}
int Mst()
{
    int i,j,k,res=0,cnt=0,l;
    memset(parent,-1,sizeof(parent));
    for(i=0;i<m;i++)
    {
        if(Find(edge[i].x)!=Find(edge[i].y))
        {
            res+=edge[i].w;
            tmp[cnt]=i;
            cnt++;
            Union(edge[i].x,edge[i].y);
        }
    }
    l=0;
    for(i=tmp[l];i!=tmp[cnt-1];i=tmp[++l])
    {
        k=0;
        memset(parent,-1,sizeof(parent));
        for(j=0;j<m;j++)
        {
            if(j!=i&&Find(edge[j].x)!=Find(edge[j].y))
            {
                k+=edge[j].w;
                Union(edge[j].x,edge[j].y);
            }
        }
        if(ff()&&k==res)
            return -1;
    }
    return res;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
        }
        qsort(edge,m,sizeof(struct Node),cmp);
        int res=Mst();
        if(res==-1)
        {
            printf("Not Unique!\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    //while(1);
  //system("PAUSE");	
  return 0;
}
