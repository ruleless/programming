#include <stdio.h>
#include <stdlib.h>

#define Max_N 1000
#define Inf 99999999

int n,f[Max_N][Max_N];

void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(f[i][k]+f[k][j]<f[i][j])
                {
                    f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,a,b;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                {
                    f[i][j]=0;
                }
                else
                {
                    f[i][j]=Inf;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            while(j--)
            {
                scanf("%d%d",&a,&b);
                f[i][a]=b;
            }
        }
        floyd();
        b=Inf;
        for(i=1;i<=n;i++)
        {
            a=0;
            for(j=1;j<=n;j++)
            {
                if(f[i][j]>a)
                {
                    a=f[i][j];
                }
            }
            if(a<b)
            {
                k=i;
                b=a;
            }
        }
        if(b>=Inf)
        {
            printf("disjoint\n");
        }
        else
        {
            printf("%d %d\n",k,b);
        }
    }
   // while(1);
   // system("PAUSE");	
    return 0;
}
