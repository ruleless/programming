#include <cstdlib>
#include <iostream>

using namespace std;

int n,t;

void solve()
{
    int i,j,k;
    i=2;
    while(i*(i-1)/2<=t)i++;
    i--;
    k=n-i;
    int temp=i*(i-1)/2;
    for(j=0;j<t-temp;j++)k++;
    for(j=1;j<=n-i-1;j++)
    {
        printf("%d ",j);
    }
    printf("%d ",k);
    j=n;
    int c=1;
    while(c<i)
    {
        if(j!=k)
        {
            printf("%d ",j);
            c++;
        }
        j--;
    }
    printf("%d\n",j);
}

int main(int argc, char *argv[])
{
    while(scanf("%d%d",&n,&t)&&!(n==-1&&t==-1))
    {
        solve();
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
