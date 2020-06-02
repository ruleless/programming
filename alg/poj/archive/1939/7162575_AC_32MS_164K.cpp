#include <cstdlib>
#include <iostream>

using namespace std;

struct Point 
{
    double x,y;
}p[10000];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        printf("%d",n);
        for(i=0;i<n-1;i++)
        {
            printf(" %lf %lf",(p[i].x+p[i+1].x)/2,(p[i].y+p[i+1].y)/2);
        }
        printf(" %lf %lf\n",(p[0].x+p[n-1].x)/2,(p[0].y+p[n-1].y)/2);
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
