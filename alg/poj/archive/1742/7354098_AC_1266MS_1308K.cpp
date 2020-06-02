#include<iostream>
using namespace std;
int n, m, vst[100001], a[101], c[101], dp[100001][2], pre, ans;
int main()
{
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
        memset(vst, 0 , sizeof(vst));vst[0] = 1;ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = a[i]; j <= m; j++)
                if (!vst[j] && vst[pre = j - a[i]] && !(dp[pre][0] == i && dp[pre][1] == c[i]) )
                {
                    ans += (vst[j] = 1);dp[j][0] = i;
                    dp[j][1] = dp[pre][0] == i ? dp[pre][1] + 1 : 1;
                }
        printf("%d\n", ans);
    }
    return 0;
}


