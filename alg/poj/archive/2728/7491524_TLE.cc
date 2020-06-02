#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
#define eps 10e-6

#define N 1005
struct Point
{
    int x,y;
    double z;
}p[N];
double c[N][N],closedge[N],Min,Max,b[N][N];
int n;
double dis(struct Point a,struct Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0 );
}
bool vis[N];
double prim(double mid)
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=n;i++)
    {
        closedge[i]=b[1][i]*1.0-mid*c[1][i];
    }
    vis[1]=true;
    double res=0;
    for(j=1;j<=n-1;j++)
    {
        k=2;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&closedge[i]<closedge[k])
                k=i;
        vis[k]=true;
        res+=closedge[k];
        for(i=beg;i<=n;i++)
        {
            if(!vis[i]&&b[k][i]*1.0-mid*c[k][i]<closedge[i])
                closedge[i]=b[k][i]*1.0-mid*c[k][i];
        }
    }
    return res;
}
void solve()
{
    int i,j,k;
    double low=0,high=Max*1.0/Min,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        double temp=prim(mid);
        if(fabs( temp )<eps)
            break;
        if(temp<0)high=mid;
        else low=mid;
    }
    printf("%.3lf\n",mid);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int  i,j,k;
    while(scanf("%d",&n)&&n)
    {
        Min=10000008;
        Max=0;
        for(i=1;i<=n;i++)
            scanf("%d%d%lf",&p[i].x,&p[i].y,&p[i].z);
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                c[i][j]=c[j][i]=dis(p[i],p[j]);
                b[i][j]=b[j][i]=fabs(p[i].z-p[j].z);
                Min=min(Min,c[i][j]);
                Max+=b[i][j];
            }
        }
        solve();
    }
    //while(1);
    return 0;
}
