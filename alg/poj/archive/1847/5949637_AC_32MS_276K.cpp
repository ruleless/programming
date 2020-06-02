#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int u,d;
	bool operator<(const struct node a)const
	{
		return d>a.d;
	}
}temp,te;

priority_queue<struct node>que;

int edge[102][102],dist[102];
bool flag[102];
int n;

int dijk(int a,int b)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dist[i]=99999;
		flag[i]=false;
	}
	dist[a]=0;
	temp.u=a;
	temp.d=0;
	que.push(temp);
	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		if(temp.u==b)
			return dist[b];
		flag[temp.u]=true;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]&& dist[temp.u]+edge[temp.u][i]<dist[i] )
			{
				dist[i]=dist[temp.u]+edge[temp.u][i];
				te.u=i;
				te.d=dist[i];
				que.push(te);
			}
		}
	}
	return -1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,i,j,k,l;
	cin >> n >> a >> b;
	for(i = 1; i <=n; i++)       //初始化map 
        for(j = 1; j <= n; j++)
             edge[i][j] = 99999;
     
     for(i = 1; i <= n; i++){
         cin >> j;
         for(k = 1; k <= j; k++){
            cin >> l;
            if(k == 1)edge[i][l] = 0;
            else      edge[i][l] = 1;      
         }      
     }
	 printf("%d\n",dijk(a,b));
	 return 0;

}