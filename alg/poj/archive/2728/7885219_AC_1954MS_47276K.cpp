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
double c[N][N],b[N][N],closedge[N],sum,Min;
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
    return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0 );
}

/*double prim(double mid)
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
}*/
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


void solve()
{
    double low=0,high=sum/Min,mid,res;
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
        sum=0;Min=Inf;
        memset(pp,-1,sizeof(pp));
        ec=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                c[i][j]=c[j][i]=fabs(p[i].z-p[j].z);
                b[i][j]=b[j][i]=dist(p[i],p[j]);
                Min=min(Min,b[i][j]);
                sum+=c[i][j];
                add(i,j,b[i][j],c[i][j]);
                add(j,i,b[i][j],c[i][j]);
            }
        solve();
    }
    //while(1);
    return 0;
}
