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
        j*=i;
    return j;
}

int dp1(int i,int j)
{
    if(f1[i][j]!=-1)
        return f1[i][j];
    if(j==0)
        return f1[i][j]=i;
    if(array[dp1(i,j-1)]<array[dp1(i+cal(j-1),j-1)])
        f1[i][j]=dp1(i,j-1);
    else
        f1[i][j]=dp1(i+cal(j-1),j-1);
    return f1[i][j];
}
int dp2(int i,int j)
{
    if(f2[i][j]!=-1)
        return f2[i][j];
    if(j==0)
        return f2[i][j]=i;
    if(array[dp2(i,j-1)]>array[dp2(i+cal(j-1),j-1)])
        f2[i][j]=dp2(i,j-1);
    else
        f2[i][j]=dp2(i+cal(j-1),j-1);
    return f2[i][j];
}
int getK(int x)
{
    int i,j=1,k=0;
    while(j<x)
    {
        j*=2;k++;
    }
    return k;
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
        int low=min(array[dp1(i,k)],array[dp1(j-cal(k)+1,k)]);
        int high=max(array[dp2(i,k)],array[dp2(j-cal(k)+1,k)]);
        printf("%d\n",high-low);
    }
    //while(1);
    return 0;
}
