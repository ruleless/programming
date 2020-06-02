/*
bellman-ford�����·��ͼ���ڽӾ����ʾ 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define Inf 9999999
#define N 1000
int edge[N][N],dist[N],n;

bool bellman(int s)//���ڸ�Ȩ��·����ture���������򷵻�false 
{
    int i,j,k;
    for(i=1;i<=n;i++)
        dist[i]=Inf;
    dist[s]=0;
    for(k=1;k<=n-1;k++)
    {
        bool flag=true;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i]+edge[i][j]<dist[j])
                {
                    flag=false;
                    dist[j]=dist[i]+edge[i][j];
                }
            }
        }
        if(flag)
            return false;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(dist[i]+edge[i][j]<dist[j])
                return true;
    return false;
}

int main()
{
}
