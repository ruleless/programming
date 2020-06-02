#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int m[500][500];
char x[500],y[500];

int dp(int i,int j)
{
    if(m[i][j]>-1)
    {
        return m[i][j];
    }
    if(i==0||j==0)
    {
        if(x[i]==y[j])
            return m[i][j]=1;
        else
            return m[i][j]=0;
    }
    if(x[i]==y[j])
    {
        return m[i][j]=dp(i-1,j-1)+1;
    }
    else
    {
        int a=dp(i-1,j);
        int b=dp(i,j-1);
        return m[i][j]=(a>b?a:b);
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    while(scanf("%s%s",x,y)!=EOF)
    {
        memset(m,-1,sizeof(m));
      //  printf("%s %s\n",x,y);
        printf("%d\n",dp(strlen(x)-1,strlen(y)-1));
    }
    //while(1);
  //system("PAUSE");	
  return 0;
}
