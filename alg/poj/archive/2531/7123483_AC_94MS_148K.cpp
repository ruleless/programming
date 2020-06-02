#include <cstdlib>
#include <iostream>

using namespace std;

int c[22][22],visited[22];
int n,res;

void dfs(int k,int sum)
{
    int i,j,l;
    if(k==n)
    {
        return ;
    }
    for(i=k+1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            int s=sum;
            for(j=1;j<=n;j++)
            {
                if(visited[j])
                {
                    sum-=c[i][j];
                }
                else
                {
                    sum+=c[j][i];
                }
            }
            //printf("%d %d\n",i,sum);
            if(sum>res)
            {
                res=sum;
            }
            dfs(i,sum);
            sum=s;
            visited[i]=0;
        }
    }
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    res=0;
    for(i=2;i<=n;i++)
    {
        res+=c[1][i];
    }
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    dfs(1,res);   
    printf("%d\n",res);
    //while(1);
getchar();
    //system("PAUSE");
    return EXIT_SUCCESS;
}
