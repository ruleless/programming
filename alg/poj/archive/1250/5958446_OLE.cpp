#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	char str[100];
	string in;
	map<string,int>level;
	int n,i,m;

	while(scanf("%d",&n)!=EOF){
		level.clear();
		for(i=1;i<=n;i++){
			scanf("%s",str);
			in=str;
			level[in]++;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%s",str);
			in=str;
			printf("%d\n",level[in]);
		}
	}
	return 0;
}