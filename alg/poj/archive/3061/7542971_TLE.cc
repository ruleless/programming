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
            len=Inf;
            for(i=0;i<n;i++)
            {
                int sum=0;
                for(j=i;j>=i+1-len&&j>=0;j--)
                {
                    sum+=a[j];
                    if(sum>=s)
                    {
                        len=i-j+1;
                        break;
                    }
                }
            }
            printf("%d\n",len);
        }
    }
    //while(1);
    return 0;
}
