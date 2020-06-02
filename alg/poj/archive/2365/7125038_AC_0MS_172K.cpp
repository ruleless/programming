#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.14159256

struct Point 
{
    double x,y;
}p[105];

double dist(struct Point& a,struct Point& b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int n,i,j,k;
    double r;
    scanf("%d%lf",&n,&r);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    double res=0;
    for(i=1;i<n;i++)
    {
        res+=dist(p[i],p[i-1]);
    }
    res+=dist(p[n-1],p[0]);
    res+=2*PI*r;
    printf("%.2lf\n",res);
    //while(1);
    return EXIT_SUCCESS;
}
