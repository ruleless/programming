#include <stdio.h>
#include <stdlib.h>

int cnt;

void solve(int num)
{
    char s1[6],s2[6];
    int i,j,k,num1,num2;
    sprintf(s1,"%d",num);
    sprintf(s2,"%d",num);
    for(i=0;i<strlen(s1);i++)
    {
        for(j=i+1;j<strlen(s1);j++)
        {
            if(s1[j]<s1[i])
            {
                char temp=s1[j];
                s1[j]=s1[i];
                s1[i]=temp;
            }
        }
    }
    for(i=0;i<strlen(s2);i++)
    {
        for(j=i+1;j<strlen(s2);j++)
        {
            if(s2[j]>s2[i])
            {
                char temp=s2[j];
                s2[j]=s2[i];
                s2[i]=temp;
            }
        }
    }
    sscanf(s1,"%d",&num1);
    sscanf(s2,"%d",&num2);
    //printf("%d %d\n",num1,num2);
    if(num2-num1==6174||num2-num1==0)
    {
        cnt++;
        printf("%d-%d=%d\n",num2,num1,num2-num1);
        printf("Ok!! %d times\n",cnt);
        return;
    }
    else
    {
        cnt++;
        printf("%d-%d=%d\n",num2,num1,num2-num1);
        solve(num2-num1);
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,n;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        cnt=0;
        printf("N=%d:\n",n);
        char temp[6];
        sprintf(temp,"%d",n);
        if(temp[0]==temp[1]&&temp[0]==temp[2]&&temp[0]==temp[3])
        {
            printf("No!!\n");
        }
        else
        {
            solve(n);
        }
    }
    //while(1);
    return 0;
}
