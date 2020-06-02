#pragma warning(disable:4786)
#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;

int edge[202][202];
bool flag[202];
int dist[202];
int n;

map<string,int>Map;

int dijk(int a,int b)
{
	memset(flag,0,sizeof(flag));
	int i,j,Max;
	flag[a]=true;
	for(i=1;i<=n;i++)
		dist[i]=edge[a][i];
	for(i=1;i<=n-2;i++)
	{
		for(Max=1;flag[Max]==true;Max++);
		for(j=Max+1;j<=n;j++)
			if(!flag[j])
				if(dist[j]>dist[Max])
					Max=j;
		flag[Max]=true;
		if(Max==b)
			return dist[Max];
		for(j=1;j<=n;j++)
		{
			if(!flag[j])
			{
				if((dist[Max]<edge[Max][j]?dist[Max]:edge[Max][j])>dist[j])
					dist[j]=(dist[Max]<edge[Max][j]?dist[Max]:edge[Max][j]);
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int r,k,i,j,ton,a,b,ca=1;
	string str1,str2;
	while( scanf("%d%d",&n,&r)!=EOF&&!(n==0&&r==0) )
	{
		Map.clear();
		k=1;
		memset(edge,0,sizeof(edge));
		while(r--)
		{
			cin>>str1>>str2>>ton;
			if(Map.find(str1)==Map.end()&&Map.find(str2)==Map.end())
			{
				Map[str1]=k;k++;
				Map[str2]=k;
				edge[k][k-1]=ton;
				edge[k-1][k]=ton;
				k++;
			}
			else if(Map.find(str1)!=Map.end()&&Map.find(str2)==Map.end())
			{
				a=Map.find(str1)->second;
				Map[str2]=k;b=k;k++;
				edge[a][b]=ton;
				edge[b][a]=ton;
			}
			else if(Map.find(str1)==Map.end()&&Map.find(str2)!=Map.end())
			{
				a=Map.find(str2)->second;
				Map[str1]=k;b=k;k++;
				edge[a][b]=ton;
				edge[b][a]=ton;
			}
			else
			{
				a=Map.find(str2)->second;
				b=Map.find(str1)->second;
				edge[a][b]=ton;
				edge[b][a]=ton;
			}
		}
		cin>>str1>>str2;
		a=Map.find(str1)->second;
		b=Map.find(str2)->second;
	//	printf("%d %d\n",a,b);
	
	//	printf("%d\n",n);
	/*	for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d ",edge[i][j]);

			printf("\n");
		}*/
		printf("Scenario #%d\n",ca);
		dijk(a,b);
		printf("%d tons\n\n",dist[b]);
	//	printf("%d\n",dist[4]);
		ca++;
	}
	return 0;
}