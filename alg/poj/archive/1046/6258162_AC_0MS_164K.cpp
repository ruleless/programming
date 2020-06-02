#include<iostream>
using namespace std;

struct node
{
	int x,y,z;
}nod[16];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,min;
	for(i=0;i<16;i++)
	{
		scanf("%d%d%d",&nod[i].x,&nod[i].y,&nod[i].z);
	}
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z),!(x==-1&&y==-1&&z==-1))
	{
		j=0;
		min=((x-nod[j].x)*(x-nod[j].x)+(y-nod[j].y)*(y-nod[j].y)+(z-nod[j].z)*(z-nod[j].z));
		for(i=1;i<16;i++)
		{
			if(((x-nod[i].x)*(x-nod[i].x)+(y-nod[i].y)*(y-nod[i].y)+(z-nod[i].z)*(z-nod[i].z))
				<min)
			{
				j=i;
				min=((x-nod[j].x)*(x-nod[j].x)+(y-nod[j].y)*(y-nod[j].y)+(z-nod[j].z)*(z-nod[j].z));
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,nod[j].x,nod[j].y,nod[j].z);
	}
	return 0;
}