#pragma warning (disable:4786)
#include<iostream>
#include<cmath>
#include<map>
using namespace std;


struct nod
{
	int x,y;
	bool operator<(const struct nod &aa)const
	{
		if(x==aa.x)
			return y<aa.y;
		else
			return x<aa.x;
	}
}temp;




struct nod vex[1003];

map<struct nod,int>Map;

int main()
{
//	freopen("in.txt","r",stdin);
	float x1,x2,x,y1,y2,y;
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF&&n)
	{
		k=0;
		Map.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&vex[i].x,&vex[i].y);
			Map[vex[i]]=1;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
			//	printf("%d %d\n",i,j);
				if(vex[i].y!=vex[j].y)
				{

	     		//	printf("%d %d\n",i,j);
	      			x1=float(vex[i].x);
	     			x2=float(vex[j].x);
		    		y1=float(vex[i].y);
		    		y2=float(vex[j].y);
		    		x=x1+sqrt( ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(1+((x1-x2)/(y1-y2))*((x1-x2)/(y1-y2)) ) );
			    	if(x-int(x)!=0)
			    		goto loop1;
			    	temp.x=int(x);
			    	y=(x1-x2)/(y1-y2)*(x1-x)+y1;
			    	if(y-int(y)!=0)
			    		goto loop1;
		    		temp.y=int(y);
			     	if(Map[temp]!=1)
			    		goto loop1;
   
		     		x1=float(vex[i].x);
	     			x2=float(vex[j].x);
		    		y1=float(vex[i].y);
		    		y2=float(vex[j].y);
	     			x=x2+sqrt( ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(1+((x1-x2)/(y1-y2))*((x1-x2)/(y1-y2)) ) );
		    		if(x-int(x)!=0)
		     			goto loop1;
		    		temp.x=int(x);
	    			y=(x1-x2)/(y1-y2)*(x2-x)+y2;
			    	if(y-int(y)!=0)
			    		goto loop1;
		    		temp.y=int(y);
		     		if(Map[temp]==1)
		     			k++;


loop1:          	x1=float(vex[i].x);
		    		x2=float(vex[j].x);
		    		y1=float(vex[i].y);
		     		y2=float(vex[j].y);
		     		x=x1-sqrt( ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(1+((x1-x2)/(y1-y2))*((x1-x2)/(y1-y2)) ) );
		    		if(x-int(x)!=0)
		    			continue;
	     			temp.x=int(x);
		    		y=(x1-x2)/(y1-y2)*(x1-x)+y1;
		    		if(y-int(y)!=0)
		     			continue;
		    		temp.y=int(y);
		    		if(Map[temp]!=1)
			    		continue;

		    		x1=float(vex[i].x);
		    		x2=float(vex[j].x);
			    	y1=float(vex[i].y);
		    		y2=float(vex[j].y);
		    		x=x2-sqrt( ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(1+((x1-x2)/(y1-y2))*((x1-x2)/(y1-y2)) ) );
		    		if(x-int(x)!=0)
			    		continue;
		     		temp.x=int(x);
		    		y=(x1-x2)/(y1-y2)*(x2-x)+y2;
		    		if(y-int(y)!=0)
	     				continue;
		    		temp.y=int(y);
		       		if(Map[temp]==1)
			    		k++;

				}
				else
				{
			//		printf("%d %d\n",i,j);
					temp.x=vex[i].x;
					temp.y=vex[i].y+vex[i].x-vex[j].x;
					if(Map[temp]!=1)
						goto loop2;
				//	printf("%d %d\n",temp.x,temp.y);
					temp.x=vex[j].x;
					temp.y=vex[j].y+vex[i].x-vex[j].x;
					if(Map[temp]==1)
					{
				//		printf("%d %d\n",temp.x,temp.y);
						k++;
					}

loop2:          	temp.x=vex[i].x;
					temp.y=vex[i].y+vex[j].x-vex[i].x;
					if(Map[temp]!=1)
						continue;
				//	printf("%d %d\n",temp.x,temp.y);
					temp.x=vex[j].x;
					temp.y=vex[j].y+vex[j].x-vex[i].x;
					if(Map[temp]==1)
					{
					//	printf("%d %d\n",temp.x,temp.y);
						k++;
					}
				}
			}
		printf("%d\n",k/4);
	}
	return 0;
}
