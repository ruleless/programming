#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1010
int pp[N],ec,n,A,B,dfn[N],low[N],stack[N],belong[N],top,index,cnt,dd;
bool instack[N];

struct Point 
{
    int x,y;
}point[N],S[2],same[N],opt[N];

struct Edge
{
    int to,next;
}e[N*N];
inline void add(int u,int v)
{
    e[ec].to=v;
    e[ec].next=pp[u];
    pp[u]=ec++;
}
void tarjan(int u)
{
    int i,j,k;
    dfn[u]=low[u]=++index;
    stack[++top]=u;
    instack[u]=true;
    for(i=pp[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else if(dfn[v]<low[u]&&instack[v])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        do{
            j=stack[top--];
            instack[j]=false;
            belong[j]=cnt;
        }while(j!=u);
        cnt++;
    }
}
bool check()
{
    int i,j,k;
    index=top=cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    for(i=0;i<2*n;i++)
        if(!dfn[i])
            tarjan(i);
    for(i=0;i<n;i++)
        if(belong[2*i]==belong[2*i+1])
            return false;
    return true;
}
void build1()
{
    int i,j,k,ii,jj,a,b,aa,bb;
    ec=0;
    memset(pp,-1,sizeof(pp));
    for(i=0;i<A;i++)
    {
        a=2*opt[i].x;b=2*opt[i].y;
        aa=a+1;bb=b+1;
        add(a,bb);add(b,aa);
        
        a=2*opt[i].x+1;b=2*opt[i].y+1;
        aa=a-1;bb=b-1;
        add(a,bb);add(b,aa);
    }
    for(i=0;i<B;i++)
    {
        a=2*same[i].x;b=2*same[i].y+1;
        aa=a+1;bb=b-1;
        add(a,bb);add(b,aa);
        
        a=2*same[i].x+1;b=2*same[i].y;
        aa=a-1;bb=b+1;
        add(a,bb);add(b,aa);
    }
}

void build(int mid)
{
    int i,j,k,ii,jj,a,b,aa,bb;
    ec=0;
    memset(pp,-1,sizeof(pp));
    for(i=0;i<A;i++)
    {
        a=2*opt[i].x;b=2*opt[i].y;
        aa=a+1;bb=b+1;
        add(a,bb);add(b,aa);
        
        a=2*opt[i].x+1;b=2*opt[i].y+1;
        aa=a-1;bb=b-1;
        add(a,bb);add(b,aa);
    }
    for(i=0;i<B;i++)
    {
        a=2*same[i].x;b=2*same[i].y+1;
        aa=a+1;bb=b-1;
        add(a,bb);add(b,aa);
        
        a=2*same[i].x+1;b=2*same[i].y;
        aa=a-1;bb=b+1;
        add(a,bb);add(b,aa);
    }
    for(i=0;i<n;i++)
    {
        for(ii=0;ii<2;ii++)
        {
            for(j=i+1;j<n;j++)
            {
                for(jj=0;jj<2;jj++)
                {
                    if(abs(point[i].x-S[ii].x)+abs(point[i].y-S[ii].y)+abs(S[ii].x-S[jj].x)+abs(S[ii].y-S[jj].y)+
                    abs(point[j].x-S[jj].x)+abs(point[j].y-S[jj].y)>mid)
                    {
                        a=2*i+ii;b=2*j+jj;
                        if(ii==0)aa=a+1;
                        else aa=a-1;
                        if(jj==0)bb=b+1;
                        else bb=b-1;
                        add(a,bb);add(b,aa);
                    }
                }
            }
        }
    }
}
void solve()
{
    int i,j,k,low=0,high=10000000,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        build(mid);
        if(check())
            high=mid;
        else
            low=mid+1;
    }
    printf("%d\n",high);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d%d%d",&n,&A,&B)==3)
    {
        for(i=0;i<2;i++)
            scanf("%d%d",&S[i].x,&S[i].y);
        for(i=0;i<n;i++)
            scanf("%d%d",&point[i].x,&point[i].y);
        for(k=0;k<A;k++)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            opt[k].x=i;
            opt[k].y=j;
        }
        for(k=0;k<B;k++)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            same[k].x=i;
            same[k].y=j;
        }
        build1();
        if(!check())
            printf("-1\n");
        else
            solve();
    }
    //while(1);
    return 0;
}
