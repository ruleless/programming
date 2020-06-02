#include <cstdlib>
#include <iostream>

using namespace std;

struct Point 
{
    int x,y;
}point[800],tp1,tp2;
int n,res;

int sum(int i,int j)
{
    int k,l=2;
    for(k=0;k<n;k++)
    {
        if(k!=i&&k!=j)
        {
            tp1.x=point[k].x-point[i].x;
            tp1.y=point[k].y-point[i].y;
            tp2.x=point[k].x-point[j].x;
            tp2.y=point[k].y-point[j].y;
            if(tp1.x*tp2.y==tp1.y*tp2.x)
            {
                l++;
            }
        }
    }
    return l;
}

void solve()
{
    int i,j,k=0,l;
    res=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            l=2;
            for(k=j+1;k<n;k++)
            {
                tp1.x=point[k].x-point[i].x;
                tp1.y=point[k].y-point[i].y;
                tp2.x=point[k].x-point[j].x;
                tp2.y=point[k].y-point[j].y;
                if(tp1.x*tp2.y==tp1.y*tp2.x)
                {
                    l++;
                }
            }
            if(l>res)
            {
                res=l;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        solve();
        printf("%d\n",res);
    }
    //while(1);
    //system("PAUSE");
    return 0;
}
