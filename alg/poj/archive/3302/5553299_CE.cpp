#include<istream>
#include<cstring>
using namespace std;


int main()
{
//	freopen("in.txt","r",stdin);
	char s1[130],s2[130],*s3;
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s1,s2);
        j=0;
		k=0;
    	while(k<strlen(s1))
		{
			if(s2[j]==s1[k])
			{
				j++;k++;
			}
			else
				k++;
			if(j==strlen(s2))
				break;
		}
		if(j==strlen(s2))
		{
			printf("YES\n");
		}
		else
		{
			j=0;
    		k=0;
			s3=strrev(s2);
			strcpy(s2,s3);
        	while(k<strlen(s1))
			{
		    	if(s2[j]==s1[k])
				{
		     		j++;k++;
				}
		    	else
		    		k++;
		    	if(j==strlen(s2))
		    		break;
			}
			if(j==strlen(s2))
			{
		    	printf("YES\n");
			}
			else 
				printf("NO\n");
		}
	}
	return 0;
}
