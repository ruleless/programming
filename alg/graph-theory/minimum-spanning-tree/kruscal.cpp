/*
kruscal求最小生成树 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000
struct Edge
{
    int u,v,w;
}e[100000];
int parent[N],cnt,n;
int Find(int x)
{
    if(parent[x]<0)
        return x;
    int r=Find(parent[x]);
    parent[x]=r;
    return r;
}
void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b)parent[a]=b;
}
int cmp(const void* a,const void* b)
{
    return ((struct Edge*)a)->w-((struct Edge*)b)->w;
}
void kruscal()
{
    int i,j,k=0;
    memset(parent,-1,sizeof(parent));
    qsort(e,cnt,sizeof(struct Edge),cmp);
    for(i=0;i<cnt;i++)
        if(Find(e[i].u)!=Find(e[i].v))
        {
            Union(e[i].u,e[i].v);
            k++;
            if(k==n-1)
                break;
        }
}
int main()
{
}
