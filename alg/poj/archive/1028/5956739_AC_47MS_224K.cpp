#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

string ctr,cur;
stack<string>back,ford;

int main()
{
//	freopen("in.txt","r",stdin);
	cur="http://www.acm.org/";
	while(cin>>ctr&&ctr!="QUIT")
	{
		if(ctr=="VISIT")
		{
			back.push(cur);
			cin>>cur;
			cout<<cur<<endl;
			
			while(!ford.empty())
				ford.pop();
		}
		else if(ctr=="BACK")
		{
			if(back.empty())
				cout<<"Ignored\n";
			else
			{
				ford.push(cur);
				cur=back.top();
				back.pop();
				cout<<cur<<endl;
			}
		}
		else 
		{
			if(ford.empty())
				cout<<"Ignored\n";
			else
			{
				back.push(cur);
				cur=ford.top();
				ford.pop();
				cout<<cur<<endl;
			}
		}
	}
	return 0;
}