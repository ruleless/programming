#include <cstdlib>
#include <iostream>

using namespace std;

struct Point 
{
    int x,y;
}point[800],tp1,tp2;
int n,res;

int sum(int i,int j,int& m)
{
    int k,l=0;
    m=i>j?i:j;
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
                if(k>m)
                {
                    m=k;
                }
            }
        }
    }
    return l;
}

void solve()
{
    int i,j,k=0,m;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int temp=sum(i,j,m);
            if(temp>k)
            {
                k=temp;
                res=m;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        solve();
        printf("%d\n",res+1);
    }
   // while(1);
    //system("PAUSE");
    return 0;
}
