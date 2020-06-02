#include<iostream>
using namespace std;

int best,t,R,S;
char aa[22][22];
bool visit[22]={false};

struct Move{
	int x,y;
};

struct Move move[4]={
	{0,-1},{-1,0},{0,1},{1,0}
};

bool ok(int x,int y)
{
	int a,b;
	int i;
	for(i=0;i<4;i++)
	{
		a=x+move[i].x;
		b=y+move[i].y;
		if( (a>=0&&a<R)&&(b>=0&&b<S)&&(!visit[aa[a][b]-'A']) )
			return false;
	}
	return true;
}

void dfs(int x,int y)
{
	if(ok(x,y))
	{
		if(t>best)
			best=t;
		return;
	}
	int i,a,b;
	for(i=0;i<4;i++)
	{
		a=x+move[i].x;
		b=y+move[i].y;
		if( (a>=0&&a<R)&&(b>=0&&b<S)&&(!visit[aa[a][b]-'A']) )
		{
			visit[aa[a][b]-'A']=true;
			t++;
			dfs(a,b);
			visit[aa[a][b]-'A']=false;
			t--;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	scanf("%d%d",&R,&S);
	for(i=0;i<R;i++)
		scanf("%s",aa[i]);
	best=0;t=0;
	visit[aa[0][0]-'A']=true;
	dfs(0,0);
	printf("%d\n",best+1);
	return 0;
}