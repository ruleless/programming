/*
二分图匹配 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000
int n;//二分图左边节点数
int m;//二分图右边节点数
bool edge[N][N],vis[N];
int link[N];

bool Find(int a)//判断从二分图左边节点a是否可以在右边找到匹配节点 
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(edge[a][i]&&!vis[i])
        {
            vis[i]=true;
            if(link[i]==-1||Find(link[i]))
            {
                link[i]=a;
                return true;
            }
        }
    }
    return false;
}

int solve()
{
    int i,k=0;
    memset(link,-1,sizeof(link));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(Find(i))
            k++;
    }
    return k;
}

int main()
{
}
