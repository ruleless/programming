/*
spfa求最短路,用静态邻接表保存图，用栈来实现 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Inf 9999999
#define N 1000
struct Edge
{
    int to,w,next;
}e[100000];
int pp[N],ec,n,sta[N],dist[N];
bool insta[N];

void spfa(int s)
{
    int i,j,k,top=0;
    memset(insta,0,sizeof(insta));
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    sta[++top]=s;
    insta[s]=true;
    while(top!=0)
    {
        k=sta[top--];
        insta[k]=false;
        for(i=pp[k];i!=-1;i=e[i].next)
            if(dist[k]+e[i].w<dist[e[i].to])
            {
                dist[e[i].to]=dist[k]+e[i].w;
                if(!insta[e[i].to])
                {
                    sta[++top]=e[i].to;
                    insta[e[i].to]=true;
                }
            }
    }
}
int main()
{
}
