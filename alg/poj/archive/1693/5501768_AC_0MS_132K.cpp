#include<iostream>
using namespace std;

struct node
{
	int x1,y1,x2,y2;
};

int main()
{
	//freopen("in.txt","r",stdin);
	int m,s,i,k,j,x1,x2,y1,j1,k1,y2,x,y,cnt,chh,css;
	node hh[100],ss[100];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		cnt=0;
		chh=0;css=0;
		scanf("%d",&s);
		for(j=1;j<=s;j++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(y1==y2)
			{
				hh[chh].x1=x1;hh[chh].x2=x2;
				hh[chh].y1=y1;hh[chh].y2=y2;
				chh++;
			}
			if(x1==x2)
			{
				ss[css].x1=x1;ss[css].x2=x2;
				ss[css].y1=y1;ss[css].y2=y2;
				css++;
			}
		}
		/*printf("%d %d\n",chh,css);
		for(k=0;k<chh;k++)
			printf("%d %d %d %d\n",hh[k].x1,hh[k].y1,hh[k].x2,hh[k].y2);
		for(k=0;k<css;k++)
			printf("%d %d %d %d\n",ss[k].x1,ss[k].y1,ss[k].x2,ss[k].y2);*/
		for(j=0;j<chh-1;j++)
			for(k=j+1;k<chh;k++)
				for(j1=0;j1<css-1;j1++)
					for(k1=j1+1;k1<css;k1++)
						if(((hh[k].x1<hh[k].x2)?hh[k].x1:hh[k].x2)<=((ss[j1].x1<ss[k1].x1)?ss[j1].x1:ss[k1].x1)
							&&((hh[k].x1>hh[k].x2)?hh[k].x1:hh[k].x2)>=((ss[j1].x1>ss[k1].x1)?ss[j1].x1:ss[k1].x1)
							&&((hh[j].x1<hh[j].x2)?hh[j].x1:hh[j].x2)<=((ss[j1].x1<ss[k1].x1)?ss[j1].x1:ss[k1].x1)
							&&((hh[j].x1>hh[j].x2)?hh[j].x1:hh[j].x2)>=((ss[j1].x1>ss[k1].x1)?ss[j1].x1:ss[k1].x1)
							&&((ss[j1].y1<ss[j1].y2)?ss[j1].y1:ss[j1].y2)<=((hh[k].y1<hh[j].y1)?hh[k].y1:hh[j].y1)
							&&((ss[j1].y1>ss[j1].y2)?ss[j1].y1:ss[j1].y2)>=((hh[k].y1>hh[j].y1)?hh[k].y1:hh[j].y1)
							&&((ss[k1].y1<ss[k1].y2)?ss[k1].y1:ss[k1].y2)<=((hh[k].y1<hh[j].y1)?hh[k].y1:hh[j].y1)
							&&((ss[k1].y1>ss[k1].y2)?ss[k1].y1:ss[k1].y2)>=((hh[k].y1>hh[j].y1)?hh[k].y1:hh[j].y1)
							)
							cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
