#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;
#define MaxN 40
int n;
double f[MaxN][MaxN];

int floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(f[i][k]*f[k][j]>f[i][j])
                {
                    f[i][j]=f[i][k]*f[k][j];
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
                if(f[i][j]*f[j][i]>1)
                {
                    return 1;
                }
        }
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    map<string,int>Map;
    string a,b;
    double c;
    int i,j,k,m,cse=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        Map.clear();
        cse++;
        k=1;
        for(i=1;i<=n;i++)
        {
            cin>>a;
            Map[a]=k++;
        }
        scanf("%d",&m);
        memset(f,0,sizeof(f));
        while(m--)
        {
            cin>>a>>c>>b;
            f[Map[a]][Map[b]]=c;
        }
        if(floyd())
        {
            printf("Case %d: Yes\n",cse);
        }
        else
        {
            printf("Case %d: No\n",cse);
        }
    }
    //while(1);
    //system("PAUSE");
    return 0;
}
