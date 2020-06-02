
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static const int N = 100;
static __int64 dp[N][N];

__int64 solve(int n, int lastNum)
{
	if (n == 1)
	{
		dp[n][lastNum] = 1;
		return 1;
	}

	if (lastNum == 1)
	{
		if (dp[n - 1][0] == -1)
		{
			dp[n - 1][0] = solve(n - 1, 0);
		}
		return dp[n - 1][0];
	}
	else
	{
		if (dp[n - 1][1] == -1)
		{
			dp[n - 1][1] = solve(n - 1, 1);
		}
		if (dp[n - 1][0] == -1)
		{
			dp[n - 1][0] = solve(n - 1, 0);
		}
		return dp[n - 1][0] + dp[n - 1][1];
	}
}

int main(int argc, char* argv[])
{
	int nCase = 0;
	scanf("%d", &nCase);
	for (int i = 0; i < nCase; ++i)
	{
		int n = 0;
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		printf("Scenario #%d:%lld\n\n", i + 1, solve(n, 1) + solve(n, 0));
	}
	return 0;
}