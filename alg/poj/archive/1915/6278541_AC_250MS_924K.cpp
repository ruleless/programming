#include<iostream>
#include<queue>
using namespace std;

struct Move
{
	int x,y;
}s,t,tmp,tmp1;
struct Move move[8]={{-2,-1},{2,-1},{2,1},{-2,1},{-1,-2},{1,-2},{1,2},{-1,2}};

int visit[305][305],prev[100000],l;

void bfs()
{
	memset(visit,false,sizeof(visit));
	queue<struct Move>que;
	que.push(s);
	visit[s.x][s.y]=true;
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		for(int i=0;i<8;i++)
		{
			tmp1.x=tmp.x+move[i].x;
			tmp1.y=tmp.y+move[i].y;
			if( (tmp1.x>=0&&tmp1.x<l)&&(tmp1.y>=0&&tmp1.y<l) )
			{
				if(!visit[tmp1.x][tmp1.y])
				{
					visit[tmp1.x][tmp1.y]=true;
					que.push(tmp1);
					prev[tmp1.x*l+tmp1.y]=tmp.x*l+tmp.y;
					if(tmp1.x==t.x&&tmp1.y==t.y)
					{
						
						while(!que.empty())
							que.pop();
						return;
					}			
				}
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&l);
		scanf("%d%d",&s.x,&s.y);
		scanf("%d%d",&t.x,&t.y);
		bfs();
		int cnt=0,i,j;
		j=t.x*l+t.y;
		i=prev[j];
		while(j!=s.x*l+s.y)
		{
			cnt++;
			j=i;
			i=prev[j];
		}
		printf("%d\n",cnt);
	}
}