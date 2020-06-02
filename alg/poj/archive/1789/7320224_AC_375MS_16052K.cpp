#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

#define MAXN 2002

int n,visited[MAXN],closedge[MAXN],edge[MAXN][MAXN];
char str[MAXN][9];
int res;
#define MAX 1220000
struct Node
{
	int u,d;
	bool operator< (const struct Node a)const
	{
		return d>a.d;
	}
}t1,t2;

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
	int i,j,k;
	memset(visited,0,sizeof(visited));
	for(i=1;i<=n;i++)
	{
		closedge[i]=MAX;
	}
	closedge[1]=0;
	t1.u=1;
	t1.d=0;
	priority_queue<struct Node> que;
	que.push(t1);
	while(!que.empty())
	{
		t1=que.top();
		que.pop();
		int u=t1.u;
		if(visited[u])
		{
			continue;
		}
		res+=closedge[u];
		visited[u]=true;
		for(i=1;i<=n;i++)
		{
			if(!visited[i]&&edge[u][i]<closedge[i])
			{
				closedge[i]=edge[u][i];
				t2.u=i;
				t2.d=closedge[i];
				que.push(t2);
			}
		}
	}
}

int main(int argc, char *argv[])
{
  //  freopen("in.txt","r",stdin);
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

