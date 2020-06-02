#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAXN 30020
#define MAXE 2000000
#define INF 0x3fffffff

int ne,nv,index,s,t,net[MAXN];
struct Edge{
    int next,pair;
    int v,cap,flow;
}edge[MAXE];
void add(const int& u,const int& v,const int& val)
{
    edge[index].next = net[u];
    net[u] = index;
    edge[index].v = v;
    edge[index].cap = val;
    edge[index].flow = 0;
    edge[index].pair = index+1;
    ++index;
    edge[index].next = net[v];
    net[v] = index; 
    edge[index].v = u;
    edge[index].cap = 0;
    edge[index].flow = 0;
    edge[index].pair = index - 1;
    ++index;
}
int ISAP()
{
    long numb[MAXN],dist[MAXN],curedge[MAXN],pre[MAXN];
    long cur_flow,max_flow,u,tmp,neck,i;
    memset(dist,0,sizeof(dist));
    memset(numb,0,sizeof(numb));
    for(i = 1 ; i <= nv ; ++i)
        curedge[i] = net[i];
    numb[nv] = nv;
    max_flow = 0;
    u = s;
    while(dist[s] < nv)
    {
        /* first , check if has augmemt flow */
        if(u == t)
        {
            cur_flow = INF;
            for(i = s; i != t;i = edge[curedge[i]].v) 
            {  
                if(cur_flow > edge[curedge[i]].cap)
                {
                    neck = i;
                    cur_flow = edge[curedge[i]].cap;
                }
            }
            for(i = s; i != t; i = edge[curedge[i]].v)
            {
                tmp = curedge[i];
                edge[tmp].cap -= cur_flow;
                edge[tmp].flow += cur_flow;
                tmp = edge[tmp].pair;
                edge[tmp].cap += cur_flow;
                edge[tmp].flow -= cur_flow;
            }

            max_flow += cur_flow;
            u = s;
        }
        /* if .... else ... */
        for(i = curedge[u]; i != -1; i = edge[i].next)
            if(edge[i].cap > 0 && dist[u] == dist[edge[i].v]+1)
                break;
        if(i != -1)
        {
            curedge[u] = i;
            pre[edge[i].v] = u;
            u = edge[i].v;
        }else{
            if(0 == --numb[dist[u]]) break;
            curedge[u] = net[u];
            for(tmp = nv,i = net[u]; i != -1; i = edge[i].next)
                if(edge[i].cap > 0)
                    tmp = tmp<dist[edge[i].v]?tmp:dist[edge[i].v];
            dist[u] = tmp + 1;
            ++numb[dist[u]];
            if(u != s) u = pre[u];
        }
    }
    return max_flow;
}
int main()
{
    int n,m,i,j,val,a,b;
    index = 0;
    scanf("%d%d",&n,&m);
    s = n + 1;
    t = n + 2;
    nv = t;
    memset(net,-1,sizeof(net));
    for(i = 1;i <= n; ++i)
    {
        scanf("%d%d",&a,&b);
        add(s,i,a);
        add(i,t,b);
    }
    for(i = 1;i <= m; ++i)
    {
        scanf("%d%d%d",&a,&b,&val);
        edge[index].next = net[a];
        net[a] = index;
        edge[index].v = b;
        edge[index].cap = val;
        edge[index].flow = 0;
        edge[index].pair = index+1;
        ++index;
        edge[index].next = net[b];
        net[b] = index;
        edge[index].v = a;
        edge[index].cap = val;
        edge[index].flow = 0;
        edge[index].pair = index - 1;
        ++index;
    }
    printf("%d\n",ISAP());
    return 0;
}

