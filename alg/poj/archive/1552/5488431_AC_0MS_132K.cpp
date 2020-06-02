#include<iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int array[16],i,j,k,cnt;
	while(1)
	{
		for(i=0;scanf("%d",&array[i]),array[i]!=0&&array[i]!=-1;i++);
			//printf("%d ",array[i]);		
		if(array[0]==-1)break;
		//putchar('\n');
		cnt=0;
		for(j=0;j<=i-2;j++)
			for(k=j+1;k<=i-1;k++)
				if(array[k]==2*array[j]||array[j]==2*array[k])
					cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
