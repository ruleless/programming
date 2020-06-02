#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1005
#define eps 1e-7
#define Inf 1e10

struct Point
{
    double x,y,z;
}point[N];
double c[N][N],b[N][N],closedge[N];
int n;
bool vis[N];

double dist(struct Point a,struct Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

double prim(double mid)
{
    int i,j,k;
    double res=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        closedge[i]=Inf;
    closedge[1]=0;
    for(j=1;j<=n;j++)
    {
        k=1;
        while(vis[k])k++;
        int beg=k;
        for(i=k+1;i<=n;i++)
            if(!vis[i]&&closedge[i]<closedge[k])
                k=i;
        vis[k]=true;
        res+=closedge[k];
        for(i=beg;i<=n;i++)
        {
            if(!vis[i]&&c[i][k]-mid*b[i][k]<closedge[i])
                closedge[i]=c[i][k]-mid*b[i][k];
        }
    }
    return res;
}

void solve()
{
    int i,j,k;
    double low=0,high=Inf,mid;
    while(true)
    {
        mid=(low+high)/2.;
        double temp=prim(mid);
        if(fabs(temp)<eps)
        {
            printf("%.3lf\n",mid);
            break;
        }
        else if(temp>0)
            low=mid;
        else
            high=mid;
    }
}

int main()
{
   // freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&point[i].x,&point[i].y,&point[i].z);
        }
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                if(i==j)
                {
                    c[i][j]=b[i][j]=0;
                }
                else
                {
                    c[i][j]=c[j][i]=fabs(point[i].z-point[j].z);
                    b[i][j]=b[j][i]=dist(point[i],point[j]);
                }
            }
        solve();
    }
   // while(1);
    return 0;
}
