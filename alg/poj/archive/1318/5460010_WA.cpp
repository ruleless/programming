#include<iostream>
#include<string>
using namespace std;

int strcmp1(char*p,char*q)
{
	int *flag=new int[strlen(q)],i,j,n=strlen(q);
	for(i=0;i<n;i++)
		flag[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(flag[j]==0&&p[i]==q[j])
			{
				flag[j]=1;break;
			}
		}
	}
	for(i=0;i<n&&flag[i]==1;i++);
	if(i==n)
		return 1;
	else
		return 0;
}


int main()
{
	//ifstream infile("t.txt",ios::in);//
	char*word[100],test[8];
	int i,num,flag;
	for(i=0;i<100;i++)
		word[i]=new char[8];
	num=0;
	cin.getline(word[num],8);
	while(word[num][0]!='X')
	{
		num++;cin.getline(word[num],8);
	}
	cin.getline(test,8);
	while(test[0]!='X')
	{
		flag=0;
		for(i=0;i<num;i++)
		{
			if(strlen(test)!=strlen(word[i]))
			{
				continue;
			}
			if(strcmp1(test,word[i])==1)
			{
				cout<<word[i]<<endl;flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"NOT A VALID WORD"<<endl;
			cout<<"******"<<endl;
		}
		else
	    	cout<<"******"<<endl;
		cin.getline(test,8);
	}
	return 0;
}