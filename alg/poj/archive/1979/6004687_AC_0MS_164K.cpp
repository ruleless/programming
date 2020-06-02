#include<iostream>
using namespace std;

int m,n;
char s[25][25];
bool flag[25][25];
struct Move
{
	int x;
	int y;
	
};
struct Move move[4]={{-1,0},{0,-1},{1,0},{0,1}};

void dfs(int i,int j)
{
//	printf("%d %d\n",i,j);
	int a,b,k;
	for(k=0;k<4;k++)
	{
		a=i+move[k].x;
		b=j+move[k].y;
		if(a>=0&&a<m&&b>=0&&b<n)
		{
			if(s[a][b]=='.'&&flag[a][b]==false)
				break;
		}
	}
	if(k==4)
		return;
	for(k=0;k<4;k++)
	{
		a=i+move[k].x;
		b=j+move[k].y;
	//	printf("%d %d\n",a,b);
		if(a>=0&&a<m&&b>=0&&b<n)
		{
			if(s[a][b]=='.'&&flag[a][b]==false)
			{
				flag[a][b]=true;
				dfs(a,b);
			}
		}
	}
}

int main()
{
//	printf("%d %d\n",move[0].x,move[0].y);
//	freopen("in.txt","r",stdin);
	int i,j,k;
	bool f;
	while(scanf("%d%d",&n,&m)!=EOF&&!(m==0&&n==0))
	{
		memset(flag,0,sizeof(flag));
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		f=false;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			//	printf("%c",s[i][j]);
				if(s[i][j]=='@')
				{
					f=true;
					break;
				}
			}
			if(f)
				break;
		}
//		printf("%d %d\n",i,j);
		flag[i][j]=true;
		dfs(i,j);
		k=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(flag[i][j])
					k++;
		printf("%d\n",k);
	}
	return 0;
}