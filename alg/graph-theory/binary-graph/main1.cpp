/*
����ͼƥ�� 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000
int n;//����ͼ��߽ڵ���
int m;//����ͼ�ұ߽ڵ���
bool edge[N][N],vis[N];
int link[N];

bool Find(int a)//�жϴӶ���ͼ��߽ڵ�a�Ƿ�������ұ��ҵ�ƥ��ڵ� 
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
