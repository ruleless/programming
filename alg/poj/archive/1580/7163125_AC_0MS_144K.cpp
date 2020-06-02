#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

char str1[200],str2[200];

int f(int a,int b)
{
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,n1,n2,up,down;
    while(scanf("%s",str1)!=EOF&&strcmp(str1,"-1")!=0)
    {
        up=0;
        scanf("%s",str2);
        n1=strlen(str1);
        n2=strlen(str2);
        down=n1+n2;
        for(i=0;i<n1;i++)
        {
            int sum=0;
            for(j=i;j<n1&&j-i<n2;j++)
            {
                if(str1[j]==str2[j-i])
                {
                    sum++;
                }
            }
            if(sum>up)
            {
                up=sum;
            }
        }
        for(i=0;i<n2;i++)
        {
            int sum=0;
            for(j=i;j<n2&&j-i<n1;j++)
            {
                if(str2[j]==str1[j-i])
                {
                    sum++;
                }
            }
            if(sum>up)
            {
                up=sum;
            }
        }
        if(up==0)
        {
            printf("appx(%s,%s) = 0\n",str1,str2);
        }
        else if(up*2==down)
        {
            printf("appx(%s,%s) = 1\n",str1,str2);
        }
        else
        {
            printf("appx(%s,%s) = %d/%d\n",str1,str2,up*2/f(up*2,down),down/f(up*2,down));
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
