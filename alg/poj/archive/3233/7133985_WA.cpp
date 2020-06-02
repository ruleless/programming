#include <cstdlib>
#include <iostream>

using namespace std;

int A[33][33],B[66][66],m,n,res[66][66];

void mul(int k)
{
    int i,j,l;
    if(k==1)
    {
        memcpy(res,B,sizeof(B));
        return;
    }
    int t1[66][66],t2[66][66];
    mul(k/2);
    memcpy(t1,res,sizeof(res));
    memset(t2,0,sizeof(t2));
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=2*n;j++)
        {
            for(l=1;l<=2*n;l++)
            {
                t2[i][j]=(t2[i][j]+(t1[i][l]*t1[l][j])%m)%m;
            }
        }
    }
    if(k%2==0)
    {
        memcpy(res,t2,sizeof(t2));
        return;
    }
    else
    {
        memset(t1,0,sizeof(t1));
        for(i=1;i<=2*n;i++)
        {
            for(j=1;j<=2*n;j++)
            {
                for(l=1;l<=2*n;l++)
                {
                    t1[i][j]=(t2[i][j]+(B[i][l]*t2[j][l])%m)%m;
                }
            }
        }
        memcpy(res,t1,sizeof(t1));
    }
}

int main(int argc, char *argv[])
{
//    freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            B[i][j]=A[i][j];
            B[i][j+n]=A[i][j];
        }
    }
    for(i=n+1;i<=2*n;i++)
    {
        for(j=1;j<=n;j++)
        {
            B[i][j]=0;
        }
    }
    for(i=n+1;i<=2*n;i++)
    {
        for(j=n+1;j<=2*n;j++)
        {
            if(i==j)
            {
                B[i][j]=1;
            }
            else
            {
                B[i][j]=0;
            }
        }
    }
    mul(k);
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<2*n;j++)
        {
            printf("%d ",res[i][j]%m);
        }
        printf("%d\n",res[i][j]%m);
    }
 //   while(1);
  //  system("PAUSE");
    return EXIT_SUCCESS;
}
