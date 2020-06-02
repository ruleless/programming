#include<iostream>
#include<cstring>
using namespace std;

int count(char *str)
{
	int len=strlen(str);
        int i;  
        int cnt = 0;
        int a[4] = {0};
        for(i = len - 1; i >= 0; i--) {
                switch (str[i]) {
                        case 'A':
                                a[1]++; 
                                a[2]++; 
                                a[3]++; 
                                break;  
                        case 'C':
                                a[2]++; 
                                a[3]++; 
                                cnt += a[1];
                                break;  
                        case 'G':
                                a[3]++; 
                                cnt += a[2];
                                break;  
                        case 'T':
                                cnt += a[3];
                }
        }
        return cnt;
}



int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;char str[100][51];char c[51];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",str[i]);
	}
	for(i=0;i<m;i++)
		for(j=i+1;j<m;j++)
			if(count(str[j])<count(str[i]))
			{
				strcpy(c,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],c);
			}
	for(i=0;i<m;i++)
		printf("%s\n",str[i]);
	return 0;
}