#include<iostream>   
#include<cstring>
#include<string>   
using namespace std;
const int Max=55;   
const int ff[4][2]={{1,0},{-1,0},{0,1},{0,-1}};   
char map[Max][Max];   
int g[2*Max][2*Max];   
int mark[Max][Max];   
int a1[2*Max],a2[2*Max];   
int visit[Max][Max];   
int L[2*Max];   
bool flag[2*Max];   
int n,m;   
inline bool ok(int x,int y)   
{   
     if(!visit[x][y]&&map[x][y]!='#'&&x>0&&y>0&&x<=m&&y<=n)   
         return true;   
     return false;   
}   
void bfs(int num,int x,int y)   
{   
     int que1[Max*Max],que2[Max*Max];   
     memset(visit,0,sizeof(visit));   
     int path[Max][Max]={0};   
     int head,tail;   
     head=tail=0;   
     que1[++tail]=x;   
     que2[tail]=y;   
     visit[x][y]=1;   
     while(head<tail)   
     {   
         int qx=que1[++head];   
         int qy=que2[head];   
         for(int i=0;i<4;i++)   
         {   
               int xx=qx+ff[i][0],yy=qy+ff[i][1];   
               if(ok(xx,yy))   
               {   
                   path[xx][yy]=path[qx][qy]+1;   
                   if(mark[xx][yy])   
                      g[num][mark[xx][yy]]=path[xx][yy];   
                   visit[xx][yy]=1;   
                   que1[++tail]=xx;   
                   que2[tail]=yy;   
               }     
         }   
     }   
}   
int main()   
{   
    int t;   
    scanf("%d",&t);   
    while(t--)   
    {   
         memset(mark,0,sizeof(mark));   
         memset(g,50,sizeof(g));   
         memset(flag,0,sizeof(flag));   
         memset(L,50,sizeof(L));   
         scanf("%d%d",&n,&m);   
         char s[100];   
         gets(s);   
         int num=0;   
         for(int i=1;i<=m;i++)   
         {   
            for(int j=1;j<=n;j++)   
            {   
                 scanf("%c",&map[i][j]);   
                 if(map[i][j]=='A'||map[i][j]=='S')   
                 {   
                      mark[i][j]=++num;   
                      a1[num]=i;   
                      a2[num]=j;   
                 }   
            }   
            getchar();   
         }   
         for(int i=1;i<=num;i++)   
              bfs(i,a1[i],a2[i]);   
         L[1]=0;   
         flag[1]=1;   
         for(int i=1;i<=num;i++)   
             if(!flag[i]&&L[i]>g[1][i])   
                  L[i]=g[1][i];   
         for(int i=1;i<num;i++)   
         {   
              int Min=1<<29;   
              int k=0;   
              for(int j=1;j<=num;j++)   
                 if(!flag[j]&&L[j]<Min)   
                 {   
                      Min=L[j];   
                      k=j;   
                 }   
              if(k==0) break;   
              flag[k]=1;   
              for(int j=1;j<=num;j++)   
                 if(!flag[j]&&L[j]>g[k][j])   
                      L[j]=g[k][j];   
         }   
         int ans=0;   
         for(int i=1;i<=num;i++)   
            ans+=L[i];   
         printf("%d\n",ans);   
    }   
    return 0;   
}  
