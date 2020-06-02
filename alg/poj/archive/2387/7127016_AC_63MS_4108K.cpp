#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000000

int n,edge[1005][1005],dist[1005],visited[1005];

void spfa(int s)
{
    int i,j,k;
    queue<int>que;
    for(i=1;i<=n;i++)
    {
        dist[i]=MAX;
    }
    dist[s]=0;
    memset(visited,0,sizeof(visited));
    que.push(s);
    visited[s]=1;
    while(!que.empty())
    {
        k=que.front();
        que.pop();
        visited[k]=0;
        for(i=1;i<=n;i++)
        {
            if(dist[k]+edge[k][i]<dist[i])
            {
                dist[i]=dist[k]+edge[k][i];
                if(!visited[i])
                {
                    que.push(i);
                    visited[i]=1;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            edge[i][j]=MAX;
            edge[j][i]=MAX;
        }
    }
    while(t--)
    {
        scanf("%d%d%d",&i,&j,&k);
        if(k<edge[i][j])
        {
            edge[i][j]=k;
            edge[j][i]=k;
        }
    }
    spfa(n);
    printf("%d\n",dist[1]);
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
