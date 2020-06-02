#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define min(a,b) (a<b?a:b)
#define Inf 9999999
#define N 505
int mat[N][N],node[N],dist[N],n;
bool vis[N];
int mincut()
{
    int i,j,k,maxj;
    int cut=Inf;
    for(i=1;i<=n;i++)
        node[i]=i;
    while(n>1)
    {
        maxj=2;
        for(i=2;i<=n;i++)
        {
            dist[ node[i] ]=mat[ node[1] ][ node[i] ];
            if(dist[node[i]]>dist[node[maxj]])
                maxj=i;
        }
        memset(vis,0,sizeof(vis));
        vis[node[1]]=true;
        int pre=1;
        for(j=1;j<n;j++)
        {
            if(j==n-1)
            {
                cut=min(cut,dist[node[maxj]]);
                for(i=1;i<=n;i++)
                {
                    mat[node[pre]][node[i]]=(mat[node[i]][node[pre]]+=mat[node[maxj]][node[i]]);
                }
                node[maxj]=node[n--];
                break;
            }
            vis[node[maxj]]=true;
            pre=maxj;
            maxj=-1;
            for(i=1;i<=n;i++)
            {
                if(!vis[node[i]])
                {
                    dist[node[i]]+=mat[node[pre]][node[i]];
                    if(maxj==-1||dist[node[i]]>dist[node[maxj]])
                        maxj=i;
                }
            }
        }
    }
    return cut;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mat,0,sizeof(mat));
		/*for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=Inf;*/
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            i++;j++;
            mat[i][j]+=k;
            mat[j][i]+=k;
    }
        printf("%d\n",mincut());
    }
    //while(1);
    return 0;
}
