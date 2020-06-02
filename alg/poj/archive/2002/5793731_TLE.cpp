#pragma warning (disable:4786)
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
}temp,temp1,temp2;




struct nod vex[1003];

map<struct nod,int>Map;

int main()
{
//	freopen("in.txt","r",stdin);
	int x1,x2,y1,y2;
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		k=0;
		Map.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&vex[i].x,&vex[i].y);
			Map[vex[i]]=1;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				if(vex[i].y!=vex[j].y)
				{
					x1=vex[i].x;
					x2=vex[j].x;
					y1=vex[i].y;
					y2=vex[j].y;
					temp1.x=y1-y2+x1;
					temp1.y=-x1+x2+y1;
					temp2.x=y1-y2+x2;
					temp2.y=-x1+x2+y2;
					if(Map.find(temp1)!=Map.end()&&Map.find(temp2)!=Map.end())
						k++;
					temp1.x=-y1+y2+x1;
					temp1.y=x1-x2+y1;
					temp2.x=-y1+y2+x2;
					temp2.y=x1-x2+y2;
					if(Map.find(temp1)!=Map.end()&&Map.find(temp2)!=Map.end())
						k++;
				}
				else
				{
					temp1.x=vex[i].x;
					temp1.y=vex[i].y+vex[i].x-vex[j].x;
					temp2.x=vex[j].x;
					temp2.y=vex[j].y+vex[i].x-vex[j].x;
					if(Map.find(temp1)!=Map.end()&&Map.find(temp2)!=Map.end())
					{
						k++;
					}

                	temp1.x=vex[i].x;
					temp1.y=vex[i].y+vex[j].x-vex[i].x;
					temp2.x=vex[j].x;
					temp2.y=vex[j].y+vex[j].x-vex[i].x;
					if(Map.find(temp1)!=Map.end()&&Map.find(temp2)!=Map.end())
					{
						k++;
					}
				}
			}
		printf("%d\n",k/4);
	}
	return 0;
}
