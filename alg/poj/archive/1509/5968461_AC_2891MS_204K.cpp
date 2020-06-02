#include<iostream>
#include<cstring>
using namespace std;

char str[10002],temp1[10002],temp2[10002],temp3[10002],temp4[10002],*str1,*str2;

int mid(char str[],int start,int len,char strback[])
{
    int l,i,k=0;
    l=strlen(str);
    if (start+len>l) return 0;
    for (i=start;i<start+len;i++)
        strback[k++]=str[i];
    strback[k]='\0';
    return 1;
} 

int cmp(int i,int k)
{
	int n=strlen(str);
	mid(str,0,i,temp1);
	mid(str,i,n-i,temp2);
	str1=strcat(temp2,temp1);

	mid(str,0,k,temp3);
	mid(str,k,n-k,temp4);
	str2=strcat(temp4,temp3);
	return strcmp(str1,str2);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,k,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		n=strlen(str);
		k=0;
		for(i=1;i<n;i++)
			if(cmp(i,k)==-1)
				k=i;
		printf("%d\n",k+1);
	}
	return 0;
}