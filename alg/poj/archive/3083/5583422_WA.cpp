#include <stdio.h> 
#include <string.h> 

int right[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; 
int left[4][2] = { {1,0},{0,-1},{-1,0},{0,1} }; 
char map[45][45]; 
int si, sj, ei, ej; 
int dir; 
int q[2500][2]; 
int flag[45][45]; 
int n, m; 

int dfs_left(int ni, int nj, int step) 
{ 
    if ( ni==ei && nj==ej ) 
        return step+1; 
    if ( ni<0 || ni>=n || nj<0 || nj>=m ) 
        return 0; 
    if ( map[ni][nj]=='#' ) 
        return 0; 
    dir = (dir+3)%4; 
    while ( 1 ) 
    { 
        int tmp = dfs_left( ni+left[dir][0], nj+left[dir][1], step+1 ); 
        if ( tmp>0 ) 
            break; 
        dir = (dir+1)%4; 
    } 
} 

int dfs_right(int ni, int nj, int step) 
{ 
    if ( ni==ei && nj==ej ) 
        return step+1; 
    if ( ni<0 || ni>=n || nj<0 || nj>=m ) 
        return 0; 
    if ( map[ni][nj]=='#' ) 
        return 0; 
    dir = (dir+3)%4; 
    while ( 1 ) 
    { 
        int tmp = dfs_right( ni+right[dir][0], nj+right[dir][1], step+1 ); 
        if ( tmp>0 ) 
            break; 
        dir = (dir+1)%4; 
    } 
} 


int bfs() 
{ 
    memset( flag, 0, sizeof(flag) ); 
    int head = 0; 
    int tail = 0; 
    q[tail][0] = si; 
    q[tail++][1] = sj; 
    flag[si][sj] = 1; 
    int step = 0; 
    while ( head<tail && flag[ei][ej]==0 ) 
    { 
        int tmp = tail; 
        step++; 
        while ( head<tmp && flag[ei][ej]==0 ) 
        { 
            int ni = q[head][0]; 
            int nj = q[head++][1]; 
            for ( int i=0; i<4; i++ ) 
            { 
                int ti = ni+left[i][0]; 
                int tj = nj+left[i][1]; 
                if ( ti>=0 && ti<n && tj>=0 && tj<m && flag[ti][tj]==0 
                    && map[ti][tj]!='#' ) 
                { 
                    q[tail][0] = ti; 
                    q[tail++][1] = tj; 
                    flag[ti][tj] = 1; 
                } 
            } 
        } 
    } 
    return step+1; 
} 
int main () 
{ 
	freopen("in.txt","r",stdin);
    int t; 
    scanf("%d", &t ); 
    while ( t-- ) 
    { 
        scanf("%d %d", &m, &n ); 
        for ( int i=0; i<n; i++ ) 
        { 
            scanf("%s", map[i] ); 
            for ( int j=0; j<m; j++ ) 
            { 
                if ( map[i][j] =='S' ) 
                    si = i, sj=j; 
                if ( map[i][j] =='E' ) 
                    ei = i, ej= j; 
            } 
        } 
        dir = 0; 
        printf("%d %d %d\n", dfs_left(si,sj,0), dfs_right(si,sj,0), bfs() ); 
    } 
    return 0; 
}