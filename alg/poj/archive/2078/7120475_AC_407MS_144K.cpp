#include <cstdlib>
#include <iostream>

using namespace std;

int A[10][10];
int n,res;

void shift(int i,int k)
{
    int j;
    int temp[10];
    for(j=0;j<n;j++)
    {
        temp[j]=A[i][j];
    }
    for(j=0;j<n;j++)
    {
        A[i][j]=temp[(j+k)%n];
    }
}
void rshift(int i,int k)
{
    int j;
    int temp[10];
    for(j=0;j<n;j++)
    {
        temp[j]=A[i][j];
    }
    for(j=0;j<n;j++)
    {
        A[i][j]=temp[(j-k+n)%n];
    }
}

void dfs(int k)
{
    int i,j;
    if(k==n)
    {
        int sum=0;
        for(j=0;j<n;j++)
        {
            int ts=0;
            for(i=0;i<n;i++)
            {
                ts+=A[i][j];
            }
            if(ts>sum)
            {
                sum=ts;
            }
        }
        if(res>sum)
        {
            res=sum;
        }
        return;
    }
    for(j=0;j<n;j++)
    {
        shift(k,j);
        dfs(k+1);
        rshift(k,j);
    }
}

int main(int argc, char *argv[])
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)&&n!=-1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        res=1<<30;
        dfs(1);
        printf("%d\n",res);
    }
  //  while(1);
  //  system("PAUSE");
    return EXIT_SUCCESS;
}
