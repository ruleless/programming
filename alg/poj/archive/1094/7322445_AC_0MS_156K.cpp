#include <iostream>
#include <cstdio>

using namespace std;

char str[6];
int map1[10000],map2[10000];
int n,deg[29];
bool edge[29][29];
int q[1000];
int que[1000],head,tail;

int topsort(int l)
{
	int i,j,k;
	memset(deg,0,sizeof(deg));
	memset(edge,0,sizeof(edge));
	for(i=1;i<=l;i++)
	{
		edge[map1[i]][map2[i]]=true;
	}
	int h=0,t=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(edge[i][j])
			{
				deg[j]++;
			}
		}
	}
	bool flag=true;
	for(i=0;i<n;i++)
	{
		if(!deg[i])
		{
			q[t++]=i;
			if(t-h>1)
			{
				flag=false;
			}
		}
	}
	head=tail=0;
	int size=0;
	while(h<t)
	{
		k=q[h++];
		que[tail++]=k;
		size++;
		for(i=0;i<n;i++)
		{
			if(deg[i]&&edge[k][i])
			{
				deg[i]--;
				if(deg[i]==0)
				{
					q[t++]=i;
					if(t-h>1)
					{
						flag=false;
					}
				}
			}
		}
	}
	if(flag)
	{
		if(size==n)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		if(size!=n)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,m;
	while(scanf("%d%d",&n,&m)!=EOF&&!( n==0&&m==0 ))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%s",str);
			map1[i]=str[0]-'A';
			map2[i]=str[2]-'A';
		}
		for(i=1;i<=m;i++)
		{
			k=topsort(i);
			if(k==-1)
			{
				printf("Inconsistency found after %d relations.\n",i);
				break;
			}
			else if(k==1)
			{
				printf("Sorted sequence determined after %d relations: ",i);
				for(j=head;j<tail;j++)
				{
					printf("%c",que[j]+'A');
				}
				printf(".\n");
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