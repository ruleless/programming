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
struct Edge
{
    int to;
    double cc,bb;
    int next;
}e[1000005];
int ec,pp[N];

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
        for(i=pp[k];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(!vis[v]&&e[i].cc-mid*e[i].bb<closedge[v])
            {
                closedge[v]=e[i].cc-mid*e[i].bb;
                t1.u=v;
                t1.d=closedge[v];
                que.push(t1);
            }
        }
    }
    return res;
}

void solve()
{
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
void add(int u,int v,double bb,double cc)
{
    e[ec].to=v;
    e[ec].bb=bb;
    e[ec].cc=cc;
    e[ec].next=pp[u];
    pp[u]=ec++;
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
        memset(pp,-1,sizeof(pp));
        ec=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                c[i][j]=c[j][i]=fabs(p[i].z-p[j].z);
                b[i][j]=b[j][i]=dist(p[i],p[j]);
                Min=min(Min,b[i][j]);
                Max+=c[i][j];
                add(i,j,b[i][j],c[i][j]);
                add(j,i,b[i][j],c[i][j]);
            }
        solve();
    }
    return 0;
}
