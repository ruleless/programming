#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d %d %d %d ",a,b,c,d);
        if(b-a==c-b&&d-c==c-b)
        {
            printf("%d\n",d+c-b);
        }
        else
        {
            printf("%d\n",d*c/b);
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
