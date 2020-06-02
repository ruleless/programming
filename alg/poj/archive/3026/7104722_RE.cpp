#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

char str[55][55];
int n,v1[55][55],v2[105],closedge[105],edge[105][105],x,y,node[55][55],dd[55][55];
char tstr[1000];

struct Point
{
    int xx,yy;
}p1,p2;

struct Point mov[5]={{-1,0},{0,-1},{1,0},{0,1}};

void dist(int ii,int jj)
{
    int i,j,k=0;
    queue<struct Point>que;
    int que1[55*55],que2[55*55];
    int head=0,tail=0;
    memset(v1,0,sizeof(v1));
    que1[++tail]=ii;
    que2[tail]=jj;
    /*p1.xx=ii;
    p1.yy=jj;
    que.push(p1);*/
    v1[ii][jj]=1;
    memset(dd,0,sizeof(dd));
    while(head<tail)
    {
        p1.xx=que1[++head];
        p1.yy=que2[head];
        /*p1=que.front();
        que.pop();*/
        if(str[p1.xx][p1.yy]=='A')
        {
            edge[(node[ii][jj])][(node[p1.xx][p1.yy])]=dd[p1.xx][p1.yy];
            edge[node[p1.xx][p1.yy]][node[ii][jj]]=dd[p1.xx][p1.yy];
        }
        v1[p1.xx][p1.yy]=1;
        for(i=0;i<4;i++)
        {
            p2.xx=p1.xx+mov[i].xx;
            p2.yy=p1.yy+mov[i].yy;
            if(p2.xx>=0&&p2.xx<x&&p2.yy>=0&&p2.yy<y)
            {
                if(!v1[p2.xx][p2.yy]&&str[p2.xx][p2.yy]!='#')
                {
                    /*que.push(p2);*/
                    que1[++tail]=p2.xx;
                    que2[tail]=p2.yy;
                    dd[p2.xx][p2.yy]=dd[p1.xx][p1.yy]+1;
                }
            }
        }
    }
}

int res;

void prim()
{
    int i,j,k,beg;
    memset(v2,0,sizeof(v2));
    for(i=2;i<=n;i++)
    {
        closedge[i]=edge[1][i];
    }
    v2[1]=1;
    for(j=1;j<=n-1;j++)
    {
        k=2;
        while(v2[k])k++;
        beg=k;
        for(i=k+1;i<=n;i++)
        {
            if(!v2[i]&&closedge[i]<closedge[k])
            {
                k=i;
            }
        }
        v2[k]=1;
        res+=closedge[k];
        for(i=beg;i<=n;i++)
        {
            if(!v2[i]&&edge[k][i]<closedge[i])
            {
                closedge[i]=edge[k][i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        gets(tstr);
        for(i=0;i<y;i++)
        {
            gets(str[i]);
            for(j=strlen(str[i])-1;j<x;j++)
            {
                str[i][j]='#';
            }
            str[i][j]='\0';
        }
        /*for(i=0;i<y;i++)
        {
            printf("%s\n",str[i]);
        }*/
        n=1;
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                if(str[i][j]=='A')
                {
                    node[i][j]=++n;
                }
                else if(str[i][j]=='S')
                {
                    node[i][j]=1;
                }
            }
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                if(str[i][j]=='A'||str[i][j]=='S')
                {
                    dist(i,j);
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",edge[i][j]);
            }
            printf("\n");
        }*/
        res=0;
        prim();
        printf("%d\n",res);
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
