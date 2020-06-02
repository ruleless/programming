#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int f(int n)
{
    double pi=acos(-1.0);
    double s=.5*log10(2*pi*n)+1.0*n*( log10(1.0*n)-log10(exp(1.0)) );
    return (int)s+1;
}

int main()
{
    int i,j,k;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&i);
        printf("%d\n",f(i));
    }
    return 0;
}
