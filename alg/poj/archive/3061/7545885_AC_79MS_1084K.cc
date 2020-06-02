#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 100006
int a[N],n,s;

bool check(int len)
{
    int i,j,k,sum=0;
    for(i=0;i<len;i++)
        sum+=a[i];
    if(sum>=s)
        return true;
    for(;i<n;i++)
    {
        sum-=a[i-len];
        sum+=a[i];
        if(sum>=s)
            return true;
    }
    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,cse;
    while(scanf("%d",&cse)!=EOF)
    {
        while(cse--)
        {
            scanf("%d%d",&n,&s);
            int sum=0;
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                sum+=a[i];
            }
            if(sum<s)
            {
                printf("0\n");
                continue;
            }
            int low=1,high=n,mid;
            while(low<high)
            {
                mid=(low+high)/2;
                if(check(mid))
                    high=mid;
                else
                    low=mid+1;
            }
            printf("%d\n",low);
        }
    }
    //while(1);
    return 0;
}
