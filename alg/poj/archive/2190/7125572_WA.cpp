#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    char num[20];
    int i,j,k,n;
    scanf("%s",num);
    j=10;
    int sum=0;
    for(i=0;i<10;i++)
    {
        if(num[i]=='?')
        {
            k=j;
        }
        else
        {
            if(num[i]=='X')
            {
                sum+=10*j;
            }
            else 
            {
                sum+=(num[i]-'0')*j;
            }
        }
        j--;
    }
    //printf("%d\n",j);
    if(k==1)
    {
        for(i=0;i<=10;i++)
        {
            if((sum+i*k)%11==0)
            {
                if(i==10)
                    printf("X\n");
                else
                    printf("%d\n",i);
                break;
            }
        }
    }
    else 
    {
        for(i=0;i<=9;i++)
        {
            if((sum+i*k)%11==0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
