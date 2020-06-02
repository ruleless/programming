#include<stdio.h>
#include<string.h>
#define maxn 110
#define maxm 100010

int n,m,v[maxm],w[maxn],c[maxn];
bool d[maxm];
void work() {
    int i,j,k,p;
    memset(d,0,sizeof(d));
    d[0] = true;
    for(i = 0;i < n;i ++) {
        for(j =0;j <=  m - w[i + 1];j ++) {
            if(d[j]) {
                if(d[j + w[i + 1]]) continue;
                p = j;
                for(k = 1;k <= c[i + 1];k ++) {
                    p += w[i + 1];
                    if(p > m) break;
                    d[p] = true;
                }
            }
        }
    }
    p = 0;
    for(i = 1;i <= m;i ++) {
        if(d[i]) {
            ++ p;
        }
    }
    printf("%d\n",p);
}

int main() {
//    freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d%d",&n,&m),n) {
        i = 1;
        while(i <= n) {
            scanf("%d",w + i);
            ++ i;
        }
        i = 1;
        while(i <= n) {
            scanf("%d",c + i);
            ++ i;
        }
        work();
    }
//    while(1) ;
    return 0;
}
