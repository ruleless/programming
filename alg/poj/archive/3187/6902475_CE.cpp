#include <cstdlib>
#include <iostream>

using namespace std;

int n,sum;
int a[100],temp[100],tem[100];

int add()
{
    int i,j;
    memcpy(tem,a,sizeof(a));
    for(i=2;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            temp[j]=tem[j]+tem[j-1];
        }
        memcpy(tem,temp,sizeof(temp));
    }
    return temp[n];
}

void solve()
{
    int i;
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    do
    {
        if(add()==sum)
        {
            break;
        }
    }while(next_permutation(a+1,a+n+1));
    for(i=1;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[i]);
}

int main(int argc, char *argv[])
{
    scanf("%d%d",&n,&sum);
    solve();
    //system("PAUSE");
    return EXIT_SUCCESS;
}
