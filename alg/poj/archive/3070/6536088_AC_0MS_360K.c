#include <stdio.h>
#include <stdlib.h>

int res[2][2],tmp[2][2],a[2][2];

void solve(int n)
{
    int i,j,k,l;
    if(n==1)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                res[i][j]=1;
            }
        }
        res[1][1]=0;
        return;
    }
    if(n%2==0)
    {
        solve(n/2);
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                tmp[i][j]=res[i][j];
            }
        }
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                k=0;
                for(l=0;l<2;l++)
                {
                    k+=tmp[i][l]*tmp[l][j]%10000;
                }
                res[i][j]=k%10000;
            }
        }
        return;
    }
    solve(n/2);
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            tmp[i][j]=res[i][j];
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            k=0;
            for(l=0;l<2;l++)
            {
                k+=tmp[i][l]*tmp[l][j]%10000;
            }
            res[i][j]=k%10000;
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            tmp[i][j]=res[i][j];
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            a[i][j]=1;
        }
    }
    a[1][1]=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            k=0;
            for(l=0;l<2;l++)
            {
                k+=a[i][l]*tmp[l][j]%10000;
            }
            res[i][j]=k%10000;
        }
    }
    
}

int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        if(n==0)
        {
            printf("0\n");
        }
        else
        {
            solve(n);
            printf("%d\n",res[0][1]);
        }
    }
    //while(1);
  
 // system("PAUSE");	
  return 0;
}
