#include<iostream>
using namespace std;


struct node
{
	int x,y;
};

struct node b[4],temp;

int aaa[5843];

int cmp(const void*a,const void*b)
{
	return (((struct node*)a)->x)*aaa[((struct node*)a)->y]-(((struct node*)b)->x)*aaa[((struct node*)b)->y];
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	aaa[0]=1;
	b[0].x=2;b[0].y=0;
	b[1].x=3;b[1].y=0;
	b[2].x=5;b[2].y=0;
	b[3].x=7;b[3].y=0;
	
	for(i=1;i<5843;i++)
	{
		qsort(b,4,sizeof(struct node),cmp);
		if(b[0].x*aaa[b[0].y]<b[1].x*aaa[b[1].y])
		{
			aaa[i]=b[0].x*aaa[b[0].y];
			b[0].y++;
		}
		else if(b[0].x*aaa[b[0].y]==b[1].x*aaa[b[1].y]&&b[0].x*aaa[b[0].y]<b[2].x*aaa[b[2].y])
		{
			aaa[i]=b[0].x*aaa[b[0].y];
			b[0].y++;
			b[1].y++;
		}
		else if(b[0].x*aaa[b[0].y]==b[1].x*aaa[b[1].y]&&b[0].x*aaa[b[0].y]==b[2].x*aaa[b[2].y]&&b[0].x*aaa[b[0].y]<b[3].x*aaa[b[3].y])
		{
			aaa[i]=b[0].x*aaa[b[0].y];
			b[0].y++;
			b[1].y++;
			b[2].y++;
		}
		else if(b[0].x*aaa[b[0].y]==b[1].x*aaa[b[1].y]&&b[0].x*aaa[b[0].y]==b[2].x*aaa[b[2].y]&&b[0].x*aaa[b[0].y]==b[3].x*aaa[b[3].y])
		{
			aaa[i]=b[0].x*aaa[b[0].y];
			b[0].y++;
			b[1].y++;
			b[2].y++;
			b[3].y++;
		}
	}
	while(scanf("%d",&i),i)
	{
		if(i%10==1&&i%100!=11)
		{
			printf("The %dst humble number is %d.\n",i,aaa[i-1]);
		}
		else if(i%10==2&&i%100!=12)
			printf("The %dnd humble number is %d.\n",i,aaa[i-1]);
		else if(i%10==3&&i%100!=13)
			printf("The %drd humble number is %d.\n",i,aaa[i-1]);
		else
			printf("The %dth humble number is %d.\n",i,aaa[i-1]);
	}
	return 0;
}



