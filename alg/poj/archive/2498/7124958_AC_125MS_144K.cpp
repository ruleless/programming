#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,t,l,m,n,p;
    char num[10];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",num);
        k=strlen(num);
        int sum=0;
        j=7;
        for(l=k-1;l>=0;l--)
        {
            if(j==9)
            {
                m=3;
            }
            else if(j==3)
            {
                m=7;
            }
            else
            {
                m=9;
            }
            if(num[l]=='?')
                p=m;
            else
            {
                sum+=(num[l]-'0')*m;
            }
            j=m;
        }
        //printf("%d\n",sum);
        for(l=0;num[l]!='?';l++);
        for(j=9;j>=0;j--)
        {
            num[l]='0'+j;
            sum+=(num[l]-'0')*p;
            if(sum%10==0)
            {
                printf("Scenario #%d:\n%s\n\n",i,num);
                break;
            }
            sum-=(num[l]-'0')*p;
        }
    }
getchar();
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
