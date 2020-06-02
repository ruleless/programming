#include<istream>
#include<cstring>
using namespace std;

void strrev1(char *s)
{
	char c;int n=strlen(s);
	for(int i=0;i<=n/2;i++)
	{
		c=s[i];s[i]=s[n-i-1];
		s[n-i-1]=c;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	char s1[130],s2[130];
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
			strrev1(s2);
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
