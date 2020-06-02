#include<iostream>
using namespace std;

static int stu[50005];

int Find(int x)
{
	int p=x,temp;
	while(stu[p]>=0)
		p=stu[p];
	/*while(x!=p)
	{
		temp=stu[x];stu[x]=p;x=temp;
	}*/
	return p;
}

void Union(int x,int y)
{
	int a=Find(x),b=Find(y);
	if(a==b)
		return;
	stu[x]+=stu[y];
	stu[y]=x;
	return;
}



int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,cnt,casen=0,i,j,k;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		for(k=1;k<=n;k++)
			stu[k]=-1;
		cnt=0;casen++;
		for(k=1;k<=m;k++)
		{
			scanf("%d%d",&i,&j);
			Union(i,j);
		}
		for(k=1;k<=n;k++)
			if(stu[k]<0)
				cnt++;
		printf("Case %d: %d\n",casen,cnt);
	}
	return 0;
}