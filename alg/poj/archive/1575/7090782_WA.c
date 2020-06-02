#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char c)
{
    if(c=='a'||c=='e'||c=='o'||c=='i'||c=='u')
    {
        return 1;
    }
    return 0;
}

int rule1(char*s)
{
    int i,n;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(check(s[i]))
        {
            return 1;
        }
    }
    return 0;
}

int rule2(char*s)
{
    int i,n;
    n=strlen(s);
    if(n<3)
    {
        return 1;
    }
    for(i=0;i<n-2;i++)
    {
        if( (check(s[i])==1&&check(s[i+1])==1&&check(s[i+2])==1)
        ||(check(s[i])==0&&check(s[i+1])==0&&check(s[i+2])==0) )
        {
            return 0;
        }
    }
    return 1;
}

int rule3(char * s)
{
    int i,n;
    n=strlen(s);
    for(i=0;i<n-1;i++)
    {
        if((s[i]!='e'&&s[i]!='0')&&s[i]==s[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    char s[30];
    int i,j;
    while(scanf("%s",s)!=EOF&&strcmp(s,"end")!=0)
    {
        if(rule1(s)&&rule2(s)&&rule3(s))
        {
            printf("<%s> is acceptable.\n",s);
        }
        else
        {
            printf("<%s> is not acceptable.\n",s);
        }
    }
    //while(1);
    return 0;
}
