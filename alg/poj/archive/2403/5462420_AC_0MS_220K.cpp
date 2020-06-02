#include<iostream>
#include<string>
using namespace std;

struct node
{
	char word[18];
	int salary;
};

int main()
{
	//ifstream cin("t.txt",ios::in);
	int m,n,i,ii,j,k,s;char temp[18];int*flag;
	cin>>m>>n;flag=new int[m];
	cin.ignore(1);
	node*des=new node[m];
	for(i=0;i<m;i++)
	{
		cin.getline(des[i].word,18,' ');
		cin>>des[i].salary;
		cin.ignore(1);
	}
	for(i=0;i<n;i++)
	{
		s=0;
		for(int ii=0;ii<m;ii++)
			flag[ii]=0;
		while(1)
		{//
		k=0;
		while(cin.peek()!=' '&&cin.peek()!='.'&&cin.peek()!='\n')
		{
			cin.get(temp[k]);
			k++;
		}
		temp[k]='\0';
		for(j=0;j<m;j++)
		{
			if(strcmp(temp,des[j].word)==0&&flag[j]==0)
			{
				//cout<<temp<<endl;
				s+=des[j].salary;//flag[j]=1;
				break;
			}
		}
		if(cin.peek()=='.')
		{
			cin.ignore(2);break;
		}
		else
			cin.ignore(1);
		}//
		cout<<s<<endl;
	}
	return 0;
}
