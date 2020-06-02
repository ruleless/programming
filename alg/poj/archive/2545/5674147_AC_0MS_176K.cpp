#include<iostream>
using namespace std;

__int64 H[10010];

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 p1,p2,p3;
	int pp1=0,pp2=0,pp3=0,i,n;
	scanf("%I64d%I64d%I64d%d",&p1,&p2,&p3,&n);
	H[0]=1;
	for(i=1;i<=n;i++)
	{
		if(p1*H[pp1]==p2*H[pp2]&&p3*H[pp3]==p2*H[pp2])
		{
			H[i]=p1*H[pp1];
			pp1++;
			pp2++;
			pp3++;
		}
		else if(p1*H[pp1]<=(p2*H[pp2]<p3*H[pp3]?p2*H[pp2]:p3*H[pp3]))
		{
			if(p1*H[pp1]<(p2*H[pp2]<p3*H[pp3]?p2*H[pp2]:p3*H[pp3]))
			{
				H[i]=p1*H[pp1];
				pp1++;
			}
			else if(p1*H[pp1]==p2*H[pp2])
			{
				H[i]=p1*H[pp1];
				pp1++;
				pp2++;
			}
			else if(p1*H[pp1]==p3*H[pp3])
			{
				H[i]=p1*H[pp1];
				pp1++;
				pp3++;
			}
		}
		else if(p2*H[pp2]<=(p1*H[pp1]<p3*H[pp3]?p1*H[pp1]:p3*H[pp3]))
		{
			if(p2*H[pp2]<(p1*H[pp1]<p3*H[pp3]?p1*H[pp1]:p3*H[pp3]))
			{
				H[i]=p2*H[pp2];
				pp2++;
			}
			else if(p2*H[pp2]==p1*H[pp1])
			{
				H[i]=p2*H[pp2];
				pp1++;
				pp2++;
			}
			else if(p2*H[pp2]==p3*H[pp3])
			{
				H[i]=p2*H[pp2];
				pp2++;
				pp3++;
			}
		}
		else if(p3*H[pp3]<=(p2*H[pp2]<p1*H[pp1]?p2*H[pp2]:p1*H[pp1]))
		{
			if(p3*H[pp3]<(p2*H[pp2]<p1*H[pp1]?p2*H[pp2]:p1*H[pp1]))
			{
				H[i]=p3*H[pp3];
				pp3++;
			}
			else if(p3*H[pp3]==p2*H[pp2])
			{
				H[i]=p3*H[pp3];
				pp3++;
				pp2++;
			}
			else if(p3*H[pp3]==p1*H[pp1])
			{
				H[i]=p3*H[pp3];
				pp3++;
				pp1++;
			}
		}
	}
	printf("%I64d\n",H[n]);
	return 0;
}
