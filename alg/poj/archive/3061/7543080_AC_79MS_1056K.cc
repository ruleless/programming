#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 100006
#define Inf 99999999
int a[N];

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,s,n,cse,len;
    while(scanf("%d",&cse)!=EOF)
    {
        while(cse--)
        {
            scanf("%d%d",&n,&s);
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            k=0;
            for(i=0;k<s&&i<n;i++)k+=a[i];
            if(k<s)
            {
                printf("0\n");
                continue;
            }
            i--;
            len=i+1;
            int sum=k;
            k=0;
            if(i!=n-1)
                for(++i;i<n;i++)
                {
                    sum+=a[i];
                    for(j=k;sum>=s;j++)sum-=a[j];
                    k=j-1;
                    sum+=a[k];
                    if(i-k+1<len)len=i-k+1;
                }
            else
            {
                for(j=k;sum>=s;j++)sum-=a[j];
                k=j-1;
                sum+=a[k];
                if(i-k+1<len)len=i-k+1;
            }
            printf("%d\n",len);
        }
    }
    //while(1);
    return 0;
}
