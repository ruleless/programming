#include <cstdlib>
#include <iostream>

using namespace std;

int c[22][22],visited[22];
int n,res;

void dfs(int k)
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
            int m=0;
            for(j=1;j<=n;j++)
            {
                for(l=j+1;l<=n;l++)
                {
                    if(visited[j]!=visited[l])
                    {
                        m+=c[j][l];
                    }
                }
            }
           // printf("%d %d\n",i,m);
            if(m>res)
            {
                res=m;
            }
            dfs(i);
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
    dfs(1);   
    printf("%d\n",res);
getchar();
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}

