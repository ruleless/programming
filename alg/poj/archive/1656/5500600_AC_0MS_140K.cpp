#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	bool color[101][101]={false};
	int t,i,x,y,l,j,k,cnt;
	char c[6];
	scanf("%d",&t);getchar();
	for(i=1;i<=t;i++)
	{
		//printf("%d\n%d",i,t);
		cnt=0;
		scanf("%s",c);
		//printf("%s\n",c);
		scanf("%d%d%d",&x,&y,&l);getchar();
		if(strcmp(c,"BLACK")==0)
			for(j=x;j<=x+l-1;j++)
				for(k=y;k<=y+l-1;k++)
					color[j][k]=true;
		else if(strcmp(c,"WHITE")==0)
			for(j=x;j<=x+l-1;j++)
				for(k=y;k<=y+l-1;k++)
					color[j][k]=false;
		else if(strcmp(c,"TEST")==0)
		{
			for(j=x;j<=x+l-1;j++)
				for(k=y;k<=y+l-1;k++)
					if(color[j][k]==true)
						cnt++;
			printf("%d\n",cnt);
		}
		//printf("%d\n",i);
	}
	return 0;
}

