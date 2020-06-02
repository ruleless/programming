#include<iostream>
#include<string>
using namespace std;

struct node
{
	int num,flag;
};
struct node test[20];

int main()
{
//	freopen("in.txt","r",stdin);
	int cnt,i,j;
	char str[40];
	bool flag;
	while(1)
	{
		flag=true;
		cnt=0;
		scanf("%d",&i);
		if(i==0)
			break;
		getchar();
		gets(str);
		while(strcmp(str,"right on")!=0)
		{
			test[cnt].num=i;
			if(strcmp(str,"too low")==0)
				test[cnt].flag=0;
			else if(strcmp(str,"too high")==0)
				test[cnt].flag=1;
			cnt++;
    		scanf("%d",&i);
 	    	getchar();
	        gets(str);
		}
		for(j=0;j<cnt;j++)
			if((test[j].num>=i&&test[j].flag==0)||(test[j].num<=i&&test[j].flag==1))
			{
				flag=false;
				break;
			}
		if(flag==true)
			printf("Stan may be honest\n");
		else
			printf("Stan is dishonest\n");
	}
	return 0;
}

