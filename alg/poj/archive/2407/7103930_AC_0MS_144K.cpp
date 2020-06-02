#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,res,i,j;
    while(scanf("%d",&n)!=EOF&&n)
    {
        res=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                res=res-res/i;
                do
                {
                    n/=i;
                }while(n%i==0);
            }
        }
        if(n!=1)
        {
            res=res-res/n;
        }
        printf("%d\n",res);
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
