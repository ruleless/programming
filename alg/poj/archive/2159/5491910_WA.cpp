#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	char a1[101],a2[101],temp[101];
	int i,j,cnt1[26]={0},cnt2[26]={0},t;
	scanf("%s",a1);
	scanf("%s",a2);
	//printf("%s\n",a1);
	//printf("%s",a2);
	for(i=0;i<strlen(a1);i++)
	{
		cnt1[int(a1[i]-'A')]++;
		cnt2[int(a2[i]-'A')]++;
	}
	for(i=0;i<=25;i++)
		for(j=i+1;j<=25;j++)
			if(cnt1[j]>cnt1[i])
			{
				t=cnt1[i];cnt1[i]=cnt1[j];cnt1[j]=t;
			}
	for(i=0;i<=25;i++)
		for(j=i+1;j<=25;j++)
			if(cnt2[j]>cnt2[i])
			{
				t=cnt2[i];cnt2[i]=cnt2[j];cnt2[j]=t;
			}
	for(i=0;i<=25&&cnt1[i]==cnt2[2];i++);
	if(i==26)
		printf("NO");
	else printf("YES");



	return 0;
}
