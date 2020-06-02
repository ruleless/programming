#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
	float low,high;
};

struct Node node[1002];

bool cmp(const struct Node&a,const struct Node&b)
{
	if(a.low==b.low)
	{
		if(a.high<=b.high)
			return true;
		else if(a.high>b.high)
			return false;
	}
	else 
	{
		if(a.low<=b.low)
			return true;
		else if(a.low>b.low)
			return false;
	}
}

int main()
{
	struct Node temp;
//	freopen("in.txt","r",stdin);
	int n,d,cnt=0,i,sum,a,b;
	bool flag;
	vector<struct Node> node;
	vector<struct Node>::iterator it1,it2;
	while(scanf("%d%d",&n,&d),!(n==0&&d==0))
	{
		node.clear();
		sum=1;
		cnt++;
		flag=true;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(abs(b)==d)
			{
				temp.low=temp.high=float(a);
				node.push_back(temp);
			}
			else if(abs(b)>d)
			{
				flag=false;
			}
			else
			{
				temp.low=(float)a-float(sqrt(double(d*d-b*b)));
				temp.high=(float)a+float(sqrt(double(d*d-b*b)));
				node.push_back(temp);
			}
		}
	//	printf("%d\n",node.size());
		if(flag==false)
			printf("Case %d: -1\n",cnt);
		else
		{
			sort(node.begin(),node.end(),cmp);
			it1=node.begin();
			for(it2=node.begin();it2!=node.end();it2++)
			{
				if(it2->low>it1->high)
				{
					sum++;
					it1=it2;
				}
			}
			printf("Case %d: %d\n",cnt,sum);
		}
	}
	return 0;
}
