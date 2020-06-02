#pragma warning(disable:4786)
#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;

int n;
string str[1000006],s;
int cnt;
int a[202];
char temp[202];
map<string,int>Map;
map<string,int>::iterator it;

bool check(int k)
{
	int i;
	for(i=0;i<k;i++)
		if(a[k]==a[i])
			return false;
	return true;
}

void dfs(int level)
{
	int i;
	if(level==n-1)
	{
		for(i=0;i<n;i++)
		{
			temp[i]=s.at(a[i]);
		}
		temp[i]='\0';
		Map[string(temp)]=1;
		return;
	}
	for(i=0;i<n;i++)
	{
		a[level+1]=i;
		if(check(level+1))
			dfs(level+1);
	}
}

int cmp(const void* a,const void* b)
{
	if( *((string*)a)<*((string*)b) )
		return -1;
	else if( *((string*)a)>*((string*)b) )
		return 1;
	return 0;
}

int main()
{
	cin>>s;
	Map.clear();
	n=s.length();
	cnt=0;
	int i;
	for(i=0;i<n;i++)
	{
		a[0]=i;
		dfs(0);
	}
	for(it=Map.begin();it!=Map.end();it++)
	{
		str[cnt]=it->first;
		cnt++;
	}
	qsort(str,cnt,sizeof(string),cmp);
	for(i=0;i<cnt;i++)
		cout<<str[i]<<endl;

	return 0;
}