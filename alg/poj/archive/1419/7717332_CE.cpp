#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 105
bool edge[MAXN][MAXN];
int res[MAXN];
int n;
void clique(int n, int* u, bool mat[][MAXN], int size, int& max, int& bb, int* res, int* rr, int* c) {
	int i, j, vn, v[MAXN];
	if (n) {
		if (size + c[u[0]] <= max) return;
		for (i = 0; i < n + size - max && i < n; ++ i) {
			for (j = i + 1, vn = 0; j < n; ++ j)
				if (mat[u[i]][u[j]])
					v[vn ++] = u[j];
			rr[size] = u[i];
			clique(vn, v, mat, size + 1, max, bb, res, rr, c);
			if (bb) return;
		}
	} else if (size > max) {
		max = size;
		for (i = 0; i < size; ++ i)
			res[i] = rr[i];
		bb = 1;
	}
}

int maxclique(int n, bool mat[][MAXN], int *ret) {
	int max = 0, bb, c[MAXN], i, j;
	int vn, v[MAXN], rr[MAXN];
	for (c[i = n - 1] = 0; i >= 0; -- i) {
		for (vn = 0, j = i + 1; j < n; ++ j)
			if (mat[i][j])
				v[vn ++] = j;
		bb = 0;
		rr[0] = i;
		clique(vn, v, mat, 1, max, bb, ret, rr, c);
		c[i] = max;
	}
	return max;
}

int main()
{
    ／／freopen("in.txt","r",stdin);
    int i,j,k,t,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                edge[i][j]=edge[j][i]=true;
        while(m--)
        {
            scanf("%d%d",&i,&j);
            i--,j--;
            edge[i][j]=edge[j][i]=false;
        }
        int cnt=maxclique(n,edge,res);
        printf("%d\n",cnt);
        for(i=0;i<cnt-1;i++)
            printf("%d ",res[i]+1);
        printf("%d\n",res[i]+1);
    }
    return 0;
}
