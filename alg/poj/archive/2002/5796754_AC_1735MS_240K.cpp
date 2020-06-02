#pragma warning(disable:4786)
#include<iostream>
#include<cmath>
#include<map>
using namespace std;


struct nod
{
	int x,y;
	bool operator<(const struct nod &aa)const
	{
		if(x==aa.x)
			return y<aa.y;
		else
			return x<aa.x;
	}
}temp1;


map<struct nod,int>Map;

struct nod vex[1003];

int main()
{
//	freopen("in.txt","r",stdin);
	int x1,x2,y1,y2;
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		Map.clear();
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&vex[i].x,&vex[i].y);
			Map[vex[i]]=1;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
					x1=vex[i].x;
					x2=vex[j].x;
					y1=vex[i].y;
					y2=vex[j].y;
					if( (y1-y2+x1+x2)%2!=0 )
						continue;
					temp1.x=(y1-y2+x1+x2)/2;
					if( (-x1+x2+y1+y2)%2!=0 )
						continue;
					temp1.y=(-x1+x2+y1+y2)/2;
					if(Map.find(temp1)==Map.end() )
						continue;
					if( (-y1+y2+x1+x2)%2!=0 )
						continue;
					temp1.x=(-y1+y2+x1+x2)/2;
					if( (x1-x2+y1+y2)%2!=0 )
						continue;
					temp1.y=(x1-x2+y1+y2)/2;
					if(Map.find(temp1)!=Map.end() )
						k++;

			}
		printf("%d\n",k/2);
	}
	return 0;
}

