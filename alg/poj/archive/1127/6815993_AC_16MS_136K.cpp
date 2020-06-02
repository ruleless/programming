#include<iostream>
using namespace std;

struct Point 
{
	int x,y;
};

struct Seg
{
	struct Point A,B;
}seg[20];

int parent[20],n;

int Find(int x)
{
	if(parent[x]<0)
		return x;
	int r=Find(parent[x]);
	parent[x]=r;
	return r;
}

void Union(int a,int b)
{
	int x=Find(a);
	int y=Find(b);
	if(x==y)
		return ;
	parent[x]+=parent[y];
	parent[y]=x;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

bool paichi(struct Point A,struct Point B,struct Point C,struct Point D)
{
	if(max(A.y,B.y)<min(C.y,D.y)||min(A.y,B.y)>max(C.y,D.y))
		return false;
	if(max(A.x,B.x)<min(C.x,D.x)||min(A.x,B.x)>max(C.x,D.x))
		return false;
	return true;
}

bool segcon(struct Point A,struct Point B,struct Point C,struct Point D)
{
	if(!paichi(A,B,C,D))
		return false;
	struct Point tp1,tp2,tp3;
	int xmul1,xmul2,xmul3,xmul4;
	tp1.x=D.x-A.x;tp1.y=D.y-A.y;
	tp2.x=B.x-A.x;tp2.y=B.y-A.y;
	tp3.x=C.x-A.x;tp3.y=C.y-A.y;
	xmul1=tp2.x*tp1.y-tp1.x*tp2.y;
	xmul2=tp3.x*tp2.y-tp2.x*tp3.y;

	tp1.x=A.x-C.x;tp1.y=A.y-C.y;
	tp2.x=D.x-C.x;tp2.y=D.y-C.y;
	tp3.x=B.x-C.x;tp3.y=B.y-C.y;
	xmul3=tp2.x*tp1.y-tp1.x*tp2.y;
	xmul4=tp3.x*tp2.y-tp2.x*tp3.y;

	if(xmul1*xmul2>=0&&xmul3*xmul4>=0)
		return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,b;
	struct Point A,B;
	while(scanf("%d",&n)&&n)
	{
		memset(parent,-1,sizeof(parent));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&A.x,&A.y,&B.x,&B.y);
			for(j=1;j<i;j++)
			{
				if(segcon(seg[j].A,seg[j].B,A,B))
					Union(i,j);
			}
			seg[i].A.x=A.x;seg[i].A.y=A.y;
			seg[i].B.x=B.x;seg[i].B.y=B.y;
		}
	//	printf("%d %d",Find(1),Find(2));
		while(scanf("%d%d",&a,&b)&&!(a==0&&b==0))
		{
			//printf("Yes");
			//printf("%d %d %d %d\n",a,parent[a],b,parent[b]);
			if(Find(a)==Find(b))
			{
				printf("CONNECTED\n");
			}
			else 
			{
				printf("NOT CONNECTED\n");
			}
		}
	}
	return 0;
}