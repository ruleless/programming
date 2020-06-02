#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 200
#define inf 10000000

typedef struct
{
    int x, y;
}point;
point house[N], men[N];
int g[N][N], lx[N], ly[N], usedx[N], usedy[N], mat[N];
/* g: 图 ，lx: 左边各点顶标，ly: 右边各点顶标， 
    usedx:给左边各点做标记，usedy:给右边各点做标记， mat:和右边点相匹配的点
*/

//找增广路径，条件是未访问过，而且两点顶标之和要等于两点之间的权

int find(int k, int n) 
{
    int i;

    usedx[k] = 1;
    for(i=1; i<=n; i++)
    {
        if(!usedy[i] && lx[k] + ly[i] == g[k][i])
        {
            usedy[i] = 1;
            if(mat[i] == -1 || find(mat[i], n))
            {
                mat[i] = k;
                return 1;
            }
        }
    }
    return 0;
}

void km(int n)
{
    int i, j, d, sum;

    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(mat, -1, sizeof(mat));

    //初始化可行顶标
    //令lx[i]为所有与顶点i关联的边的最大权
    for(i=1; i<=n; i++)
    {
        lx[i] = g[i][1];
        for(j=2; j<=n; j++)
        {
            lx[i] = lx[i] > g[i][j] ? lx[i] : g[i][j];
        }
    }

    for(int k=1; k<=n; k++)
    {
        memset(usedx, 0, sizeof(usedx));
        memset(usedy, 0, sizeof(usedy)); //善前

        while(!find(k, n)) //未找到完备匹配
        {
            for(i=1, d = inf*5; i<=k; i++)
                if(usedx[i]) //左边点在交错树中
                    for(j=1; j<=n; j++)
                        if(!usedy[j]) //右边点不在交错树中
                            d = d < lx[i] + ly[j] - g[i][j] ? d : lx[i] + ly[j] - g[i][j];


            for(i=1; i<=k; i++) //修改左边各点顶标
                if(usedx[i])
                    lx[i] -= d;
            for(i=1; i<=n; i++) //修改右边各点顶标
                if(usedy[i])
                    ly[i] += d;
            memset(usedx, 0, sizeof(usedx)); //为下次寻找善前
            memset(usedy, 0, sizeof(usedy));
        }
    }
    sum = 0;
    for(i=1; i<=n; i++)
        sum += lx[i] + ly[i];
        //sum += abs(house[i].y - men[mat[i]].y) + abs(house[i].x - men[mat[i]].x);

    sum = n * inf - sum;
    printf("%d\n", sum);
}

int main()
{
    int i, j;
    int n, m, k1, k2;
    char ch;

    //freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(!n && !m)
            break;
        memset(house, 0, sizeof(house));
        memset(men, 0, sizeof(men));
        
        k1 = 0;
        k2 = 0;
        for(i=1; i<=n; i++)
        {
            getchar();
            for(j=1; j<=m; j++)
            {
                ch = getchar();

                //记录每个H跟m的位置
                if(ch == 'H')
                {
                    house[++k1].x = j;
                    house[k1].y = i;
                }
                if(ch == 'm')
                {
                    men[++k2].x = j;
                    men[k2].y = i;
                }
            }
        }

        memset(g, 0, sizeof(g));
        for(i=1; i<=k1; i++)
        {
            for(j=1; j<=k2; j++)
            {
                //用一个很大的数去减每个H跟m的曼哈顿距离，把问题转化为最大权问题
                g[i][j] = inf-(abs(house[i].y - men[j].y) + abs(house[i].x - men[j].x));
            }
        }
        km(k1);
    }
    
    //getch();
    return 0;
}
