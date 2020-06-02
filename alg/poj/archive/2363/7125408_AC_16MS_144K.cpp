#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int f(int n)
{
    int i;
    for(i=1;i*i<=n;i++);
    return i;
}

int main(int argc, char *argv[])
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        int ans=1<<30;
        int cc=f(n);
        for(i=1;i<=cc;i++)
        {
            for(j=i;j<=cc;j++)
            {
                if(n%(i*j)==0)
                {
                    k=n/(i*j);
                    if(ans>2*(i*j+i*k+k*j))
                    {
                        ans=2*(i*j+i*k+k*j);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
   //system("PAUSE");
    return EXIT_SUCCESS;
}
