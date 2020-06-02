#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

bool edge[27][27];
int indegree[27];
queue<int>que;

int topsort(int n)
{
	stack<int>sta;
	while(!que.empty())
		que.pop();
	int i,j,v;
	bool flag=false;
	memset(indegree,0,sizeof(indegree));
	for(j=0;j<n;j++)
		for(i=0;i<n;i++)
			if(edge[i][j]==true)
				indegree[j]++;
	for(i=0;i<n;i++)
		if(indegree[i]==0)
			sta.push(i);
	if(sta.size()!=1)
		flag=true;
	while(!sta.empty())
	{
		v=sta.top();
		sta.pop();
		que.push(v);
		for(j=0;j<n;j++)
			if(edge[v][j]==true)
				if((--indegree[j])==0)
					sta.push(j);
		if(sta.size()!=1&&sta.size()!=0)
			flag=true;
	}
	if(que.size()==n)
	{
		if(flag==true)
			return -1;
		else
			return 1;
	}
	else return 0;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,i,k;
	char str[5];
	bool flag;
	while(scanf("%d%d",&n,&m),n!=0&&m!=0)
	{
		flag=false;
		memset(edge,0,sizeof(edge));
		for(i=1;i<=m;i++)
		{
			scanf("%s",str);
		//	printf("%s\n",str);
			edge[str[0]-'A'][str[2]-'A']=true;
			if(flag==false)
			{
		    	k=topsort(n);
	     		if(k==1)
				{
			    	printf("Sorted sequence determined after %d relations: ",i);
		        	while(!que.empty())
					{
			     		printf("%c",que.front()+'A');
			    		que.pop();
					}
			    	printf(".\n");
			    	flag=true;
				}
		    	else if(k==0)
				{
			    	printf("Inconsistency found after %d relations.\n",i);
			    	flag=true;
				}
			}
		}
		if(k==-1)
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}