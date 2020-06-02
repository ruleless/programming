#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n;
double edge[200][200],closedge[200],visited[200];
#define MAX 10000000000
double res;

void prim()
{
	int i,j,k,beg;
	for(i=2;i<=n;i++)
	{
		closedge[i]=edge[1][i];
	}
	memset(visited,0,sizeof(visited));
	visited[1]=1;
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

int main()
{
//	freopen("in.txt","r",stdin);
	int m,i,j,k;
	string str,str1,str2;
	double has,l;
	scanf("%lf",&has);
	scanf("%d",&n);
	map<string,int>Map;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		Map[str]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		edge[i][j]=MAX;
	}
	scanf("%d",&m);
	while(m--)
	{
		cin>>str1>>str2>>l;
		edge[Map[str1]][Map[str2]]=l;
	}
	res=0;
	prim();
	if(res>has)
	{
		printf("Not enough cable\n");
	}
	else
	{
		printf("Need %.1lf miles of cable\n",res);
	}
	return 0;
}