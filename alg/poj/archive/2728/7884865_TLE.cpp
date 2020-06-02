#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1005
#define eps 1e-5
#define Inf 1e10

struct Point
{
    double x,y,z;
}point[N];
double c[N][N],b[N][N],closedge[N],Max,Min;
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
        closedge[i]=c[1][i]-mid*b[1][i];
    vis[1]=true;
    for(j=1;j<=n-1;j++)
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
    double low=0,high=Max/Min,mid,res;
    while(high-low>eps)
    {
        mid=(low+high)/2.;
        double temp=prim(mid);
        if(fabs(temp)<eps)
            break;
        else if(temp>0)
            low=mid;
        else
            high=mid;
    }
    printf("%.3lf\n",mid);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&point[i].x,&point[i].y,&point[i].z);
        }
        Max=0,Min=Inf;
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
                    Min=min(Min,b[i][j]);
                    Max+=c[i][j];
                }
            }
        solve();
    }
    //while(1);
    return 0;
}
