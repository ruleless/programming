#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 2050
struct Edge
{
    int to,next;
}e[N*N];
int ec,pp[N],n,dfn[N],low[N],stack[N],belong[N],index,cnt,top;
bool instack[N];

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
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    for(i=0;i<2*n;i++)
        if(!dfn[i])
            tarjan(i);
   // printf("%d %d \n",belong[2],belong[3]);
    for(i=0;i<n;i++)
        if(belong[2*i]==belong[2*i+1])
        {
            //printf("%d %d \n",2*i,2*i+1);
            return false;
        }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m,a,b,aa,bb;
    char op[10];
    while(scanf("%d%d",&n,&m)==2)
    {
        ec=0;
        memset(pp,-1,sizeof(pp));
        while(m--)
        {
            scanf("%d%d%d%s",&i,&j,&k,op);
            if(strcmp(op,"AND")==0)
            {
                if(k==1)
                {
                    a=2*i;b=2*j;
                    aa=a+1;bb=b+1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i;b=2*j+1;
                    aa=a+1;bb=b-1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i+1;b=2*j;
                    aa=a-1;bb=b+1;
                    add(a,bb);add(b,aa);
                }
                else
                {
                    a=2*i+1;b=2*j+1;
                    aa=a-1;bb=b-1;
                    add(a,bb);add(b,aa);
                }
            }
            else if(strcmp(op,"OR")==0)
            {
                if(k==1)
                {
                    a=2*i;b=2*j;
                    aa=a+1;bb=b+1;
                    add(a,bb);add(b,aa);
                }
                else
                {
                    a=2*i+1;b=2*j+1;
                    aa=a-1;bb=b-1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i;b=2*j+1;
                    aa=a+1;bb=b-1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i+1;b=2*j;
                    aa=a-1;bb=b+1;
                    add(a,bb);add(b,aa);
                }
            }
            else
            {
                if(k==1)
                {
                    a=2*i;b=2*j;
                    aa=a+1;bb=b+1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i+1;b=2*j+1;
                    aa=a-1;bb=b-1;
                    add(a,bb);add(b,aa);
                }
                else
                {
                    a=2*i;b=2*j+1;
                    aa=a+1;bb=b-1;
                    add(a,bb);add(b,aa);
                    
                    a=2*i+1;b=2*j;
                    aa=a-1;bb=b+1;
                    add(a,bb);add(b,aa);
                }
            }
        }
        if(check())
            printf("YES\n");
        else
            printf("NO\n");
    }
    //while(1);
    return 0;
}
