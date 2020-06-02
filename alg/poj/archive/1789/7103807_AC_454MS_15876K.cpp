#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXN 2002

int n,visited[MAXN],closedge[MAXN],edge[MAXN][MAXN];
char str[MAXN][9];
int res;

int dist(char* s1,char* s2)
{
    int i,j=0;
    for(i=0;i<7;i++)
        if(s1[i]!=s2[i])
            j++;
    return j;
}

void prim()
{
    int i,j,k,beg;
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    for(i=2;i<=n;i++)
        closedge[i]=edge[1][i];
    for(j=1;j<=n-1;j++)
    {
        k=2;
        while(visited[k])k++;
        beg=k;
        for(i=k+1;i<=n;i++)
        {
            if(!visited[i]&&closedge[i]<closedge[k])
            {
                k=i;
            }
        }
        visited[k]=1;
        res+=closedge[k];
        for(i=beg;i<=n;i++)
        {
            if(!visited[i]&&edge[k][i]<closedge[i])
            {
                closedge[i]=edge[k][i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",str[i]);
        }
        memset(edge,0,sizeof(edge));
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                edge[i][j]=dist(str[i],str[j]);
                edge[j][i]=edge[i][j];   
            }
        }
        res=0;
        prim();
        printf("The highest possible quality is 1/%d.\n",res);
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
