#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int x,y;
};
struct node point[1002];
int x[1002],y[1002];

int main()
{
//	freopen("in.txt","r",stdin);
	int n1,n2,n3,i,j,k,l,m,cnt=0;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(i=0;i<n1;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n2;i++)
		scanf("%d",&y[i]);
	for(i=0;i<n3;i++)
		scanf("%d%d",&point[i].x,&point[i].y);
	for(i=0;i<n1;i++)
		for(j=i+1;j<n1;j++)
			for(k=0;k<n2;k++)
				for(l=k+1;l<n2;l++)
					if(abs(x[i]-x[j])==abs(y[k]-y[l]))
					for(m=0;m<n3;m++)
						if(point[m].x<=((x[i]>=x[j])?x[i]:x[j])&&point[m].x>=((x[i]<x[j])?x[i]:x[j])
							&&point[m].y<=((y[k]>=y[l])?y[k]:y[l])&&point[m].y>=((y[k]<y[l])?y[k]:y[l]))
						{
							cnt++;
							break;
						}
	printf("%d\n",cnt);
	return 0;
}