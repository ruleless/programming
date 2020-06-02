#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	int w,h;
	bool flag;
};

bool cmp(const struct node&a,const struct node&b)
{
	if(a.w==b.w)
	{
		return (a.h>b.h)?true:false;
	}
	else
		return (a.w<=b.w)?true:false;
}



int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i,j,a,b,sum;
	struct node temp;
	vector<struct node>vect;
	vector<struct node>::iterator it1,it2,it3;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d",&n);
		vect.clear();
		for(j=1;j<=n;j++)
		{
			scanf("%d%d",&a,&b);
			temp.w=a;temp.h=b;temp.flag=false;
			vect.push_back(temp);
		}
		sort(vect.begin(),vect.end(),cmp);
		for(it1=vect.begin();it1!=vect.end();it1++)
		{
			j=sum;
			it3=it1;
			if(it1->flag==false)
			{
				for(it2=it1+1;it2!=vect.end();it2++)
				{
					if(it2->flag==false&&(it2->h)>(it3->h)&&(it2->w)>(it3->w))
					{
						it2->flag=true;
						if(it3==it1)
							sum++;
						it3=it2;
					}
				}
				if(j==sum)
					sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}


