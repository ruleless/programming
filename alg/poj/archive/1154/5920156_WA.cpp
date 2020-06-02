#include<iostream>
using namespace std;

bool visit[27];
char aa[22][22];
int R,S;

struct Move
{
	int x,y;
};
struct Move move[4]={
	{0,1},{-1,0},{0,-1},{1,0}
};

int dfs(int x,int y)
{
	int i,a,b,temp,num,t;
	num=0;
	for(i=0;i<27;i++)
		if(visit[i])
			num++;
//	printf("%d\n",num);
	if(visit[aa[x][y]-'A'])
	{
		return num;
	}
	visit[aa[x][y]-'A']=true;
	temp=num;
	for(i=0;i<4;i++)
	{
		a=x+move[i].x;
		b=y+move[i].y;
		if( (a>=0&&a<R)&&(b>=0&&b<S) )
		{
			t=dfs(a,b);
		}
		if(t>temp)
			temp=t;
	}
	if(temp>num)
		return temp;
	visit[aa[x][y]-'A']=false;
	return num;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	scanf("%d%d",&R,&S);
	for(i=0;i<R;i++)
		scanf("%s",aa[i]);
	memset(visit,0,sizeof(visit));
	
	printf("%d\n",dfs(0,0));
	return 0;
}