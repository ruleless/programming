#include <stdio.h>
#include <stdlib.h>

char s1[50],s2[50],flag[2];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int a,i,j,res=0;
    while(scanf("%s",s1))
    {
        if(s1[0]=='#')
        {
            break;
        }
        else if(s1[0]=='0')
        {
            printf("%d\n",res);
            res=0;
        }
        else
        {
            scanf("%s%d%s",s2,&i,flag);
            if(flag[0]=='F')
            {
                res+=2*i;
            }
            else if(flag[0]=='B')
            {
                res+=i;
                if(i%2==1)
                {
                    res+=((i+1)/2);
                }
                else
                {
                    res+=(i/2);
                }
            }
            else
            {
                res+=(i<500?500:i);
            }
        }
    }
    //while(1);
    return 0;
}
