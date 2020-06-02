#include<iostream>
#include<string>
using namespace std;

int main()
{
	int count[10]={0},i,j,k,l,m;
	char num1[81],num2[81],temp[81];
	cin.getline(num1,80);
	for(i=strlen(num1);i<81;i++)
		num1[i]='\0';
	while(num1[0]!='-')
	{
		strcpy(num2,num1);
		for(m=1;m<=15;m++)
		{
			for(i=0;i<10;i++)
			{
			     count[i]=0;
			}
			j=0;l=0;
			for(i=0;i<strlen(num2);i++)
			{
			     count[int(num2[i])-48]++;
			}
		//	for(i=0;i<10;i++)
		//	{
		//	     cout<<count[i];
		//	}
		//	cout<<endl;
	    	while(count[j]==0)
		    	j++;
		//	cout<<j<<' ';
	    	for(k=j;k<10;k++)
			{
			    if(count[k]>9)
				{
			    	temp[l]=char(count[k]/10+48);l++;
			    	temp[l]=char(count[k]%10+48);l++;
			    	temp[l]=char(k+48);l++;
				}
		    	else if(count[k]!=0)
				{
			    	temp[l]=char(count[k]+48);l++;
			    	temp[l]=char(k+48);l++;
				}
			}
			for(i=l;i<81;i++)
				temp[i]='\0';
		//	cout<<temp<<' ';
			if(m==1&&strcmp(num2,temp)==0)
			{
				cout<<num1<<" is self-inventorying"<<endl;break;
			}
			if(strcmp(num2,temp)==0)
			{
				cout<<num1<<" is self-inventorying after "<<m-1<<" steps"<<endl;break;
			}
			if(strcmp(num1,temp)==0)
			{
				cout<<num1<<" enters an inventory loop of length "<<m<<endl;break;
			}
	    	strcpy(num2,temp);
		}
		if(m==16)
			cout<<num1<<" can not be classified after 15 iterations"<<endl;
		cin.getline(num1,80);
	}
	return 0;
}