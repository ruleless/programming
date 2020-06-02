#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 252
int array[N][N],n,b;
unsigned char f1[N][N][N],f2[N][N][N];
#define Inf 66666

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    scanf("%d%d%d",&n,&b,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&array[i][j]);
            f1[i][j][1]=array[i][j];
            f2[i][j][1]=array[i][j];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=2;k<=n;k++)
            {
                f1[i][j][k]=Inf;
                f2[i][j][k]=0;
            }
    for(k=2;k<=b;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i+k-1<=n&&j+k-1<=n)
                {
                    f1[i][j][k]=min(f1[i][j][1],f1[i+1][j+1][k-1]);
                    f1[i][j][k]=min(f1[i][j][k],f1[i][j+1][k-1]);
                    f1[i][j][k]=min(f1[i][j][k],f1[i+1][j][k-1]);
                    
                    f2[i][j][k]=max(f2[i][j][1],f2[i+1][j+1][k-1]);
                    f2[i][j][k]=max(f2[i][j][k],f2[i+1][j][k-1]);
                    f2[i][j][k]=max(f2[i][j][k],f2[i][j+1][k-1]);
                    //printf("%d %d %d %d %d\n",k,i,j,f1[i][j][k],f2[i][j][k]);
                }
            }
        }
    }
    while(m--)
    {
        scanf("%d%d",&i,&j);
        printf("%d\n",f2[i][j][b]-f1[i][j][b]);
    }
    //while(1);
    return 0;
}
