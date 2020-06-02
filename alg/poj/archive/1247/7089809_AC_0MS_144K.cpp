#include <cstdlib>
#include <iostream>

using namespace std;

int n,a[35],sum;

int solve()
{
    int i,s=0;
    for(i=1;i<=n;i++)
    {
        s+=a[i];
        sum-=a[i];
        if(s==sum)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)!=EOF&&n)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        j=solve();
        if(!j)
        {
            printf("No equal partitioning.\n");
        }
        else
        {
            printf("Sam stops at position %d and Ella stops at position %d.\n",j,j+1);
        }
    }
    //while(1);
    //system("PAUSE");
    return 0;
}
