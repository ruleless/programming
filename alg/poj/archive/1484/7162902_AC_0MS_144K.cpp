#include <cstdlib>
#include <iostream>

using namespace std;

int e[22],c;

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j=0,k,flag[22],cur,ans,n,m;
    bool res;
    while(scanf("%d%d%d",&n,&m,&c)!=EOF&&!(n==0&&m==0&&c==0))
    {
        j++;
        res=true;
        ans=0;
        cur=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&e[i]);
        }
        memset(flag,0,sizeof(flag));
        while(m--)
        {
            scanf("%d",&i);
            if(!flag[i])
            {
                cur+=e[i];
                if(cur>c)
                {
                    res=false;
                }
                if(cur>ans)
                {
                    ans=cur;
                }
                flag[i]=1;
            }
            else
            {
                cur-=e[i];
                flag[i]=0;
            }
        }
        if(res)
        {
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",j,ans);

        }
        else
        {
            printf("Sequence %d\nFuse was blown.\n\n",j);
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
