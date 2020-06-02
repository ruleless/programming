/*
floydÇó×î¶ÌÂ· 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 1000

int f[N][N],n;

void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
}

int main()
{
}
