/*
����ͼ�Ķ���ƥ�� 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000
int n,m,link[N][N];//link[i][j]��ʾ�ұߵĵ�i���ڵ�����ߵĵ�j��ƥ��ڵ㣬
                    //link[i][0]��ʾi�ڵ㵱ǰ��ƥ����Ŀ 
bool edge[N][N],vis[N];

bool Find(int a,int lim)//lim��ʾ�ұߵ�ÿ���ڵ�����ƥ����Ŀ 
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        if(edge[a][i]&&!vis[i])
        {
            vis[i]=true;
            if(link[i][0]<lim)
            {
                link[i][++link[i][0]]=a;
                return true;
            }
            else
            {
                for(j=1;j<=link[i][0];j++)
                {
                    if(Find(link[i][j],lim))
                    {
                        link[i][++link[i][0]]=a;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int solve()
{
    int i,k=0,lim;
    memset(link,0,sizeof(link));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(Find(i,lim))
            k++;
    }
    return k;
}

int main()
{
}
