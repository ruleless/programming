#include<iostream>
#include<queue>
using namespace std;

int visited[40000000],step[40000000];

int main()
{
	int v1,v2,w;
	queue<int>que;
	memset(visited,0,sizeof(visited));
	memset(step,0,sizeof(step));
	scanf("%d%d",&v1,&v2);
	if(v1==v2)
	{
		printf("0\n");
	}
	else
	{
		que.push(v1);
		visited[v1]=true;
	}
	while(!que.empty())
	{
		w=que.front();
		que.pop();
		if(visited[w-1]==false&&w-1>=0)
		{
			visited[w-1]=true;
			que.push(w-1);
			step[w-1]=step[w]+1;
			if(w-1==v2)
			{
				printf("%d\n",step[w-1]);
				break;
			}
		}
		if(visited[w+1]==false)
		{
			visited[w+1]=true;
			que.push(w+1);
			step[w+1]=step[w]+1;
			if(w+1==v2)
			{
				printf("%d\n",step[w+1]);
				break;
			}
		}
		if(visited[2*w]==false&&2*w<v2)
		{
			visited[2*w]=true;
			que.push(2*w);
			step[2*w]=step[w]+1;
			if(2*w==v2)
			{
				printf("%d\n",step[2*w]);
				break;
			}
		}
	}
	return 0;
}
