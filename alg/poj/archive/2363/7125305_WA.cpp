#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=1<<30;
        for(i=1;i<=n/3;i++)
        {
            for(j=i;j<=n/3;j++)
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
