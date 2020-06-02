#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int x,y;
};

struct nod{
	int x,y;
	struct nod* next;
};

struct nod* hash[1005]={NULL};

struct node point[1002];
int x[1002],y[1002];

int main()
{
//	freopen("in.txt","r",stdin);
	struct nod*p,*q;
	int n1,n2,n3,i,j,m,cnt=0;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(i=0;i<n1;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n2;i++)
		scanf("%d",&y[i]);
	for(i=0;i<n2-1;i++)
		for(j=i+1;j<n2;j++)
		{
			if(hash[abs(y[j]-y[i])]==NULL)
			{
				p=new nod;
				p->next=NULL;
				p->x=y[i];
				p->y=y[j];
				hash[abs(y[j]-y[i])]=p;
			}
			else
			{
				p=hash[abs(y[j]-y[i])];
				while((p->next)!=NULL)
					p=p->next;
				q=new nod;
				q->next=NULL;
				q->x=y[i];
				q->y=y[j];
				p->next=q;
			}
		}

	for(i=0;i<n3;i++)
		scanf("%d%d",&point[i].x,&point[i].y);
	for(i=0;i<n1-1;i++)
		for(j=i+1;j<n1;j++)
		{
			
			p=hash[abs(x[j]-x[i])];
			while(p!=NULL)
			{
				printf("%d %d\n",p->x,p->y);
				for(m=0;m<n3;m++)
					if(point[m].x<=((x[i]>=x[j])?x[i]:x[j])&&point[m].x>=((x[i]<x[j])?x[i]:x[j])
						&&point[m].y<=(((p->x)>=(p->y))?(p->x):(p->y))&&point[m].y>=(((p->x)<(p->y))?(p->x):(p->y)))
					{
						cnt++;break;
					}
				p=p->next;
			}
		}
	printf("%d\n",cnt);
	return 0;
}
