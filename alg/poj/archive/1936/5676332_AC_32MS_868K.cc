#include <iostream>
using namespace std;
int main()
{
	string str1,str2;
	int len1,len2,i,j;
	while(cin>>str1>>str2)
	{
		j=0;
		len1 = str1.length();
		len2 = str2.length();
		for(i = 0 ; i < len2 ; i ++)
		{
			if( str1[j] == str2[i])
			{
				j++;
			}
		}
		if(j == len1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
