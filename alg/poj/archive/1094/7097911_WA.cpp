#include<iostream>
#include<queue>

using namespace std;

char str[1005][5];
int edge[30][30];
int n,m;
queue<int>q;

int topsort(int k)
{
	int i,j;
	edge[str[k-1][0]-'A'][str[k-1][2]-'A']=1;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",edge[i][j]);
		}
		printf("\n");
	}*/
	int deg[30];
	memset(deg,0,sizeof(deg));
	queue<int>que;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(edge[i][j])
				deg[j]++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(!deg[i])
		{
			que.push(i);
		}
	}
	if(que.size()>1)
	{
		while(!q.empty())q.pop();
		return -1;
	}
	int cnt=0;
	while(!que.empty())
	{
		i=que.front();
		cnt++;
		q.push(i);
		que.pop();
		for(j=0;j<n;j++)
		{
			if(deg[j]!=0)
			{
				if(edge[i][j])
				{
					deg[j]--;
					if(deg[j]==0)
					{
						que.push(j);
					}
				}
			}
		}
		if(que.size()>1)
		{
			//printf("Yes\n");
			while(!q.empty())q.pop();
			return -1;
		}
	}
	if(cnt!=n)
	{
		return 0;
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		for(i=0;i<m;i++)
		{
			scanf("%s",str[i]);
		}
		memset(edge,0,sizeof(edge));
		for(i=1;i<=m;i++)
		{
			int back=topsort(i);
			if(back==1)
			{
				
				printf("Sorted sequence determined after %d relations: ",i);
				while(!q.empty())
				{
					printf("%c",q.front()+'A');
					q.pop();
				}
				printf(".\n");
				break;
			}
			else if(back==0)
			{
				printf("Inconsistency found after %d relations.\n",i);
				break;
			}
		}
		if(i>m)
		{
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}