#include<iostream>
#include<queue>
using namespace std;

struct Move
{
	int x,y;
}s,t,tmp,tmp1;
struct Move move[8]={{-2,-1},{2,-1},{2,1},{-2,1},{-1,-2},{1,-2},{1,2},{-1,2}};

int visit[10][10],prev[80];

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
			if( (tmp1.x>=1&&tmp1.x<=8)&&(tmp1.y>=1&&tmp1.y<=8) )
			{
				if(!visit[tmp1.x][tmp1.y])
				{
					visit[tmp1.x][tmp1.y]=true;
					que.push(tmp1);
					prev[tmp1.x*8+tmp1.y]=tmp.x*8+tmp.y;
					if(tmp1.x==t.x&&tmp1.y==t.y)
					{
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
	char s1[3],s2[3];
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		s.x=int(s1[0]-'a')+1;
		s.y=int(s1[1]-'0');
		t.x=int(s2[0]-'a')+1;
		t.y=int(s2[1]-'0');
		bfs();
		int cnt=0,i,j;
		j=t.x*8+t.y;
		i=prev[j];
		while(j!=s.x*8+s.y)
		{
			cnt++;
			j=i;
			i=prev[j];
		}
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,cnt);
	}
	return 0;
}