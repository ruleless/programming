#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    int i,j,k,t,l,m,n,p;
    char num[10];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",num);
        k=strlen(num);
        int sum=0;
        j=3;
        for(l=0;l<k;l++)
        {
            if(j==9)
            {
                m=7;
            }
            else if(j==7)
            {
                m=3;
            }
            else
            {
                m=9;
            }
            if(num[l]=='?')
                p=m;
            else
                sum+=(num[l]-'0')*m;
            j=m;
        }
        for(l=0;num[l]!='?';l++);
        for(j=0;j<=9;j++)
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
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
