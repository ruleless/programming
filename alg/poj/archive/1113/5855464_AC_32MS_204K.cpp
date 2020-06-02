#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX_NUM 1005
#define PI 3.1415926
#define EPS 1e-10
#define SW( a, b ) (t) = (a); (a) = (b); (b) = (t);
#define Q( x ) ( ( x ) * ( x ) )
struct Point
{
    double x, y;
};
Point p[ MAX_NUM ], stack[ MAX_NUM ];//最后构成凸包的顶点为stack[0]~stack[top]

int n, m, top; //n为所要求的凸包的顶点个数
double cross( Point s, Point a, Point b )
{
    return ( a.x - s.x ) * ( b.y - s.y ) - ( b.x - s.x ) * ( a.y - s.y );
}
double square_dist( Point a, Point b )
{
    return Q( a.x - b.x ) + Q( a.y - b.y );
}
bool cmp( const Point a, const Point b )
{
    double prod = cross( p[ 0 ], a, b );
    if( prod > 0 )
        return true;
    return false;
}
void Graham_scan()
{
    int i, j, flag = 0;
    for( i = 1; i < n; i++ )
        if( ( p[ flag ].y > p[ i ].y ) || ( fabs( p[ flag ].y - p[ i ].y ) < EPS && p[ flag ].x > p[ i ].x ) )
            flag = i;
    Point t;
    SW( p[ 0 ], p[ flag ] )
        sort( p + 1, p + n, cmp );
    for( i = 2, j = 1; i < n; i++ )
        if( fabs( cross( p[ 0 ], p[ i ], p[ j ] ) ) < EPS )
        {
            if( square_dist( p[ 0 ], p[ i ] ) > square_dist( p[ 0 ], p[ j ] ) )
                p[ j ] = p[ i ];
        }
        else
        {
            p[ ++j ] = p[ i ]; 
        }
        m = j;
        stack[ 0 ] = p[ 0 ];
        stack[ 1 ] = p[ 1 ];
        stack[ 2 ] = p[ 2 ];
        top = 2;
        for( i = 3; i <= m; i++ )
        {
            while( cross( stack[ top ], p[ i ], stack[ top - 1 ] ) < EPS )
                top--;
            stack[ ++top ] = p[ i ];
        }
}

double Length()
{
    double ans = 0;
    for( int i = 0; i <= top; i++ )
        ans += sqrt( Q( stack[i].x - stack[ (i+1)%(top+1) ].x ) + Q( stack[i].y - stack[ (i+1)%(top+1) ].y ) );
    return ans;
}


int main()
{
    int l, i;
    scanf("%d %d", &n, &l);
    for(i=0; i<n; ++i)
    {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    Graham_scan();
    printf("%.0lf\n", Length() + 2*PI*l );
    return 0;
}