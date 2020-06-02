#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int Max = 225;
const int oo = 210000000;

int n,m,c[Max][Max],r[Max][Max],c1[Max][Max],source,sink；

//c1是c的反向网络，用于dis数组的初始化
int dis[Max];

void initialize()// 初始化dis数组
{
     int q[Max],head = 0, tail = 0;//BFS队列
     memset(dis,0,sizeof(dis));
     q[++head] = sink;
     while(tail < head)
     {
         int u = q[++tail], v;
         for(v = 0; v <= sink; v++)
         {
               if(!dis[v] && c1[u][v] > 0)
               {
                   dis[v] = dis[u] + 1;
                   q[++head] = v;
               }
         }
     }
}

int maxflow_sap()
{
    initialize();
    int top = source, pre[Max], flow = 0, i, j, k, low[Max];

    // top是当前增广路中最前面一个点。
    memset(low,0,sizeof(low));//low数组用于保存路径中的最小容量
    while(dis[source] < n)
    {
        bool flag = false;
        low[source] = oo;
        for(i = 0; i <= sink; i++)//找允许弧，根据允许弧的定义
        {
            if(r[top][i] > 0 && dis[top] == dis[i] + 1)
            {
                flag = true;
                break;
            }
        }
        if(flag)// 如果找到允许弧
        {
            low[i] = r[top][i];
            if(low[i] > low[top]) low[i] = low[top];//更新low
            pre[i] = top; top = i;
            if(top == sink)// 如果找到一条增广路了
            {
                flow += low[sink];
                j = top;
                while(j != source)// 路径回溯更新残留网络
                {
                    k = pre[j];
                    r[k][j] -= low[sink];
                    r[j][k] += low[sink];
                    j = k;
                }
                top = source;//从头开始再找最短路
                memset(low,0,sizeof(low));
            }
        }
        else// 如果没有允许弧
        {
            int mindis = 10000000;
            for(j = 0; j <= sink; j++)//找和top相邻dis最小的点
            {
                if(r[top][j] > 0 && mindis > dis[j] + 1)
                    mindis = dis[j] + 1;
            }
            dis[top] = mindis;//更新top的距离值
            if(top != source) top = pre[top];// 回溯找另外的路
        }
    }
    return(flow);
}

