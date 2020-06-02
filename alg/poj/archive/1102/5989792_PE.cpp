#include<iostream>
#include<cstring>
using namespace std;

char num[100000000];

int main()
{
//	freopen("in.txt","r",stdin);
	int s,i,j,k,n;
	while(scanf("%d%s",&s,num)!=EOF&& !(s==0&&strcmp(num,"0")==0) )
	{
		n=strlen(num);
		for(i=1;i<=3+2*s;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==1)
				{
					if(num[j]=='1')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='2')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='3')
					{
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='4')
					{
						for(k=1;k<=s+2;k++)
							printf(" ");
					}
					else if(num[j]=='5')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
					}
					else if(num[j]=='6')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='7')
					{
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='8')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='9')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='0')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
				}
				else if(i>=2&&i<=s+1)
				{
					if(num[j]=='1')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='2')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='3')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='4')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='5')
					{
						printf("|");
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='6')
					{
						printf("|");
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='7')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='8')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='9')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='0')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
				}
				else if(i==s+2)
				{
					if(num[j]=='1')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='2')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='3')
					{
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='4')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='5')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
					}
					else if(num[j]=='6')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='7')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='8')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='9')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='0')
					{
						for(k=1;k<=s+2;k++)
							printf(" ");
					}
				}
				else if(i>=s+3&&i<=2*s+2)
				{
					if(num[j]=='1')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='2')
					{
						printf("|");
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='3')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='4')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='5')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='6')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='7')
					{
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='8')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='9')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
						printf("|");
					}
					else if(num[j]=='0')
					{
						printf("|");
						for(k=1;k<=s;k++)
							printf(" ");
						printf("|");
					}
				}
				else if(i==2*s+3)
				{
					if(num[j]=='1')
					{
						for(k=1;k<=s+1;k++)
							printf(" ");
					}
					else if(num[j]=='2')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='3')
					{
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='4')
					{
						for(k=1;k<=s+2;k++)
							printf(" ");
					}
					else if(num[j]=='5')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
					}
					else if(num[j]=='6')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
					}
					else if(num[j]=='7')
					{
						for(k=1;k<=s+2;k++)
							printf(" ");
					}
					else if(num[j]=='8')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='9')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
					else if(num[j]=='0')
					{
						printf(" ");
						for(k=1;k<=s;k++)
							printf("-");
						printf(" ");
					}
				}
				if(j!=n-1)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}