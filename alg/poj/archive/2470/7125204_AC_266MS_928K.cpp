#include <cstdlib>
#include <iostream>

using namespace std;

int a[100005],b[100005],hash[100005];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,flag,n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            hash[a[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(hash[i]!=a[i])
            {
                printf("not ambiguous\n");
                break;
            }
        }
        if(i==n+1)
        {
            printf("ambiguous\n");
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
