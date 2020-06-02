#include<iostream>
#include<cstring>
#define Max 100000
using namespace std;

int parent[Max],kind[Max];



int find(int x)
{
	int find(int x);
    int t=parent[x];
    if(t<0)return x;
    parent[x]=find(t);
    kind[x]=(kind[x]+kind[t])%2;
    return parent[x];
}




void Union(int x,int y,char* k)
{
    int root1=find(x),root2=find(y);
    if(strcmp(k,"A")==0)
    {
        if(root1!=root2)printf("Not sure yet.\n"); 
		else
        {        
			if(kind[x]==kind[y])printf("In the same gang.\n");
            else printf("In different gangs.\n");
		}
	}
	else
	{
        if(root1!=root2)
        {
            parent[root2]+=parent[root1];
            parent[root1]=root2;
            kind[root1]=(kind[y]+kind[x]+1)%2;
        }
	}    
}



int main()
{
	//freopen("in.txt","r",stdin);
	int T,N,M,i,j,k,l;
	char str[3];
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&N,&M);
		for(j=1;j<=N;j++)
		{
			kind[j]=0;
			parent[j]=-1;
		}
		for(j=1;j<=M;j++)
		{
			scanf("%s%d%d",str,&k,&l);			
			Union(k,l,str);
			//printf("%s %d\n",str,j);
		}
	}
	return 0;
}
			

