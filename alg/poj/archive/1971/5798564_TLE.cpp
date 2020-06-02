#pragma warning(disable:4786)
#include<iostream>
#include<map>
using namespace std;

struct node
{
	int x,y;
	bool operator<(const struct node &a)const
	{
		if(a.x==x)
			return y<a.y;
		return x<a.x;
	}
}temp;


struct node a[1001];

map<struct node,int>Map;
map<struct node,int>::iterator it;

int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,cnt;
	scanf("%d",&t);
	while(t--)
	{
		Map.clear();
		cnt=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				temp.x=a[i].x+a[j].x;
				temp.y=a[i].y+a[j].y;
				Map[temp]++;
			}
		for(it=Map.begin();it!=Map.end();it++)
		{
			if((it->second)>1)
				cnt+=it->second*(it->second-1)/2;
		}
		printf("%d\n",cnt);
	}
	return 0;
}