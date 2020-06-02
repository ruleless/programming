#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ok[215][215];
char s1[215],s2[215],s3[450];

int dp(int i,int j)
{
    if(ok[i][j]!=-1)
        return ok[i][j];
    if(i==0&&j==0)
    {
        return ok[i][j]=1;
    }
    if(s1[i]==s2[j])
    {
        if(s1[i]!=s3[i+j])
        {
            return ok[i][j]=0;
        }
        else
        {
            int a=dp(i-1,j);
            int b=dp(i,j-1);
            return ok[i][j]=a||b;
        }
    }
    else
    {
        if(s1[i]==s3[i+j])
        {
            return ok[i][j]=dp(i-1,j);
        }
        else if(s2[j]==s3[i+j])
        {
            return ok[i][j]=dp(i,j-1);
        }
        else 
        {
            return ok[i][j]=0;
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int n,a,b,c,cse=0,i;
    scanf("%d",&n);
    while(n--)
    {
        cse++;
        scanf("%s%s%s",s1,s2,s3);
        a=strlen(s1)+1;
        b=strlen(s2)+1;
        c=strlen(s3)+1;
        for(i=a;i>0;i--)
        {
            s1[i]=s1[i-1];
        }
        for(i=b;i>0;i--)
        {
            s2[i]=s2[i-1];
        }
        for(i=c;i>0;i--)
        {
            s3[i]=s3[i-1];
        }
        memset(ok,-1,sizeof(ok));
        if(dp(a,b))
        {
            printf("Data set %d: yes\n",cse);
        }
        else
        {
            printf("Data set %d: no\n",cse);
        }
    }
    //while(1);
  //system("PAUSE");	
  return 0;
}
