#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1005
#define Inf 10e30
#define eps 10e-8
struct Point
{
    int x,y,z;
}p[N];
double b[N][N],closedge[N],Min;
bool vis[N];
int c[N][N],n,sum;

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

double dist(struct Point x1,struct Point x2)
{
    return sqrt( (x1.x-x2.x)*(x1.x-x2.x)*1.0+(x1.y-x2.y)*(x1.y-x2.y)*1.0 );
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        sum=0;Min=Inf;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                c[i][j]=c[j][i]=abs(p[i].z-p[j].z);
                sum+=c[i][j];
                b[i][j]=b[j][i]=dist(p[i],p[j]);
                Min=min(Min,b[i][j]);
            }
        printf("%.3lf\n",solve());
    }
    //while(1);
    return 0;
}
