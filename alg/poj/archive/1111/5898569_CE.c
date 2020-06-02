#include <stdio.h>
#include <string.h>
#define max 40
char G[max][max];
bool mark[max][max];
int m,n,a,b,s;
int d[8][2]= {{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{1,1},{-1,-1}};

int dfs(int v, int u)
{
    if(G[v][u]== '.'|| mark[v][u]) return 1;
    mark[v][u]= true;
    int i, x, y;
    for(i=0; i<4; ++i)
    {
        x= v+d[i][0];
        y= u+d[i][1];
        if(G[x][y]== '.')
            s++;
    }
    for(i=0; i<8; ++i)
    {
        x= v+d[i][0];
        y= u+d[i][1];
        dfs(x,y);
    }
    return s;
}
void solve()
{
    char e[max];
    int i, j, k;
    for(i=0; i<max; ++i)
        for(j=0; j<max; ++j)
            G[i][j]= '.';
    memset(mark,false,sizeof(mark));
    s= 0;
    for(i=1; i<=m; ++i)
    {
        scanf("%s",e);
        k=0;
        for(j=1; j<=n; ++j)
            G[i][j]= e[k++];
    }
    dfs(a,b);
    printf("%d\n",s);
    return ;
}

int main()
{
    while(scanf("%d%d%d%d",&m,&n,&a,&b)!= EOF&&m&&n&&a&&b)
        solve();
    return 0;
}
