#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 50006
int array[N],n,f1[N][32],f2[N][32];

int cal(int k)
{
    int j=1;
    for(int i=1;i<=k;i++)
        j*=2;
    return j;
}

int dp1(int i,int j)
{
    if(f1[i][j]!=-1)
        return f1[i][j];
    if(j==0)
        return f1[i][j]=array[i];
    f1[i][j]=min(dp1(i,j-1),dp1(i+cal(j-1),j-1));
    return f1[i][j];
}
int dp2(int i,int j)
{
    if(f2[i][j]!=-1)
        return f2[i][j];
    if(j==0)
        return f2[i][j]=array[i];
    f2[i][j]=max(dp2(i,j-1),dp2(i+cal(j-1),j-1));
    return f2[i][j];
}
int getK(int x)
{
    if(x==1)
        return 0;
    int i,j=1,k=0;
    while(j<x)
    {
        j*=2;k++;
    }
    return k-1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(i=0;i<n;i++)
    {
        memset(f1[i],-1,sizeof(f1[i]));
        memset(f2[i],-1,sizeof(f2[i]));
    }
    while(m--)
    {
        scanf("%d%d",&i,&j);
        i--;j--;
        k=getK(j-i+1);
        //printf("%d %d %d\n",j-i+1,k,cal(k));
        int temp=cal(k);
        int low=min(dp1(i,k),dp1(j-temp+1,k));
        int high=max(dp2(i,k),dp2(j-temp+1,k));
        printf("%d\n",high-low);
    }
    //while(1);
    return 0;
}
