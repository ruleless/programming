#include<iostream>
using namespace std;

int students[30000];

int Find(int x)
{
	int temp,p=x;
	while(students[p]>=0)
		p=students[p];
	while(x!=p)
	{
		temp=students[x];
		students[x]=p;
		x=temp;
	}
	return x;
}

void Union(int r1,int r2)
{
	int a=Find(r1),b=Find(r2);
	if(a==b)
		return;
	if(students[a]<students[b])
	{
		students[a]+=students[b];students[b]=a;
	}
	else
	{
		students[b]+=students[a];students[a]=b;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n_stu,n_gro,member,n_mem,i,mem,cnt,j;
	while(scanf("%d%d",&n_stu,&n_gro),n_stu!=0||n_gro!=0)
	{
		for(i=0;i<n_stu;i++)
			students[i]=-1;
		cnt=0;
		for(i=1;i<=n_gro;i++)
		{
			scanf("%d",&n_mem);
			scanf("%d",&mem);
			for(j=1;j<n_mem;j++)
			{
				scanf("%d",&member);
				Union(mem,member);
			}
		}
		mem=Find(0);
		printf("%d\n",-students[mem]);
	}
	return 0;
}



