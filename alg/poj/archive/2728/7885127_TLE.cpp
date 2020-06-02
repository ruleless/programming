#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
#define N 1005
#define eps 10e-6
#define Inf 10e30

struct Node
{
    int u;
    double d;
    bool operator<(const struct Node a)const
    {
        return d>a.d;
    }
}t1,t2;
struct Point
{
    int x,y;
    double z;
}p[N];
double c[N][N],b[N][N],closedge[N],Max,Min;
int n;
bool vis[N];

double dist(struct Point a,struct Point b)
{
    return sqrt( 1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y) );
}

double prim(double mid)
{
    int i,j,k;
    double res=0;
    for(i=2;i<=n;i++)
        closedge[i]=Inf;
    closedge[1]=0;
    priority_queue<struct Node> que;
    memset(vis,0,sizeof(vis));
    t1.u=1;
    t1.d=0;
    que.push(t1);
    while(!que.empty())
    {
        t1=que.top();
        que.pop();
        k=t1.u;
        if(vis[k])continue;
        vis[k]=true;
        res+=closedge[k];
        for(i=1;i<=n;i++)
            if(!vis[i]&&c[i][k]*1.0-mid*b[i][k]<closedge[i])
            {
                closedge[i]=c[i][k]*1.0-mid*b[i][k];
                t1.u=i;
                t1.d=closedge[i];
                que.push(t1);
            }
    }
    return res;
}

void solve()
{
    int i,j,k;
    double low=0,high=Max*1.0/Min,mid,res;
    while(high-low>eps)
    {
        mid=(low+high)/2.0;
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
            scanf("%d%d%lf",&p[i].x,&p[i].y,&p[i].z);
        }
        Max=0;Min=Inf;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                c[i][j]=c[j][i]=fabs(p[i].z-p[j].z);
                b[i][j]=b[j][i]=dist(p[i],p[j]);
                Min=min(Min,b[i][j]);
                Max+=c[i][j];
            }
        solve();
    }
    //while(1);
    return 0;
}
