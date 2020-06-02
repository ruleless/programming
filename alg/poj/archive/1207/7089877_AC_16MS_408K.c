#include <stdio.h>
#include <stdlib.h>

int aa[10006];

void solve()
{
    int i,j,k;
    for(i=1;i<=10000;i++)
    {
        j=i;
        k=1;
        while(j!=1)
        {
            if(j%2==0)
            {
                j/=2;
                k++;
            }
            else
            {
                j=3*j+1;
                k++;
            }
        }
        aa[i]=k;
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int a,b,i,j;
    
    solve();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int res=0;
        for(i=(a<b?a:b);i<=(a>b?a:b);i++)
        {
            if(aa[i]>res)
            {
                res=aa[i];
            }
        }
        printf("%d %d %d\n",a,b,res);
    }
    //while(1);
    return 0;
}
