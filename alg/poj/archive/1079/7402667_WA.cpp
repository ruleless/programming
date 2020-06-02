#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int aa[5005],bb[5005],cnt;

int f(int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;b=r;r=a%b;
    }
    return b;
}
#define MAX 10e12
int main()
{
    int i,j,k,a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        cnt=0;
        i=f(a,b);a/=i;b/=i;double d=a*1.0/b;//printf("%.2lf\n",ceil(d));
        double tmp=MAX;
        for(i=1;i<=b;i++)
        {
            int x=(int)ceil(d*i),y=x-1;
            k=1.0*x/i-d<d-1.0*y/i?x:y;
            if(f(k,i)==1&&fabs(k*1.0/i-d)<tmp)
            {
                aa[cnt]=k,bb[cnt++]=i;
                tmp=fabs(k*1.0/i-d);
            }
        }
        for(i=0;i<cnt;i++)
        {
            printf("%d/%d\n",aa[i],bb[i]);
        }
        printf("\n");
    }
    return 0;
}
