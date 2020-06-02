/*
求最优比例生成树 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1005
#define Inf 10e30
#define eps 10e-6
struct Point
{
    int x,y;
    double z;
}p[N];
double b[N][N],closedge[N],Min,c[N][N],sum;
bool vis[N];
int n;

double prim(double mid)
{
    int i,j,k;
    double res=0;
    for(i=2;i<=n;i++)
        closedge[i]=c[1][i]*1.0-mid*b[1][i];
    memset(vis,0,sizeof(vis));
    vis[1]=true;
    for(j=1;j<=n-1;j++)
    {
        k=2;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&closedge[i]<closedge[k])
                k=i;
        res+=closedge[k];
        vis[k]=true;
        for(i=beg;i<=n;i++)
            if(!vis[i]&&c[k][i]*1.0-mid*b[k][i]<closedge[i])
                closedge[i]=c[k][i]*1.0-mid*b[k][i];
    }
    return res;
}
double solve()
{
    double low=0,high=sum*1.0/Min,mid;
    while(high-low>eps)
    {
        mid=(high+low)/2.0;
        double k=prim(mid);
        if(fabs(k)<eps)
            break;
        else if(k>0)
            low=mid;
        else high=mid;
    }
    return mid;
}
int main()
{
}
