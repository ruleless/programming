#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 1000000

char str[60][60];
int node[60][60];
int x,y,n;
int edge[60][60],dist[60][60];
struct Move
{
	int xx,yy;
};
struct Move move[4]={{-1,0},{0,-1},{1,0},{0,1}};
bool vis[60][60];
int qx[4000],qy[4000],head,tail;

void bfs(int i,int j)
{
	int k,l;
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	vis[i][j]=true;
	head=tail=0;
	qx[tail]=i;
	qy[tail++]=j;
	while(head<tail)
	{
		int ii=qx[head];
		int jj=qy[head++];
		if(node[ii][jj])
		{
			edge[ node[i][j] ][ node[ii][jj] ]=dist[ii][jj];
		}
		for(k=0;k<4;k++)
		{
			int xx=ii+move[k].xx;
			int yy=jj+move[k].yy;
			if(xx>=0&&xx<x&&yy>=0&&yy<y)
			{
				if(!vis[xx][yy]&&str[xx][yy]!='#')
				{
					qx[tail]=xx;
					qy[tail++]=yy;
					vis[xx][yy]=true;
					dist[xx][yy]=dist[ii][jj]+1;
				}
			}
		}
	}
}

int closedge[60];
bool vis1[60];

int prim()
{
	int i,j,k,res=0;
	memset(vis1,0,sizeof(vis1));
	for(i=1;i<=n;i++)
	{
		closedge[i]=edge[1][i];
	}
	vis1[1]=true;
	for(j=1;j<=n-1;j++)
	{
		k=1;
		while(vis1[k])k++;
		int beg=k;
		for(i=k+1;i<=n;i++)
		{
			if(!vis1[i]&&closedge[i]<closedge[k])
			{
				k=i;
			}
		}
		vis1[k]=true;
		res+=closedge[k];
		for(i=1;i<=n;i++)
		{
			if(!vis1[i]&&edge[k][i]<closedge[i])
			{
				closedge[i]=edge[k][i];
			}
		}
	}
	return res;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&y,&x);
		char temp[30];
		gets(temp);
		for(i=0;i<x;i++)
		{
			gets(str[i]);
		}
		memset(node,0,sizeof(node));
		n=0;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				if(str[i][j]=='A'||str[i][j]=='S')
				{
					node[i][j]=++n;
				}
			}
		}
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				if(node[i][j])
				{
					bfs(i,j);
				}
			}
		}
		printf("%d\n",prim());
	}
	return 0;
}