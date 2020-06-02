
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100001
static int sArr[N];
static int maxSegSum[N];
static int maxInverseSegSum[N];

int getMax(int a, int b)
{
    return a > b ? a : b;
}

void getMaxSegSum(int *a, int *out, int n)
{
    int curSegMaxSum = 0;
    out[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        // curSegMaxSum = getMax(curSegMaxSum + a[i], 0);
        curSegMaxSum = getMax(curSegMaxSum, curSegMaxSum + a[i]);
        out[i] = getMax(out[i > 0 ? i - 1 : 0], curSegMaxSum);
    }
}

void getMaxInverseSum(int *a, int *out, int n)
{
    int curSegMaxSum = 0;
    out[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        // curSegMaxSum = getMax(curSegMaxSum + a[i], 0);
        curSegMaxSum = getMax(curSegMaxSum, curSegMaxSum + a[i]);
        out[i] = getMax(out[i < n - 1 ? i + 1 : n - 1], curSegMaxSum);
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    while (scanf("%d", &n) != EOF && n > 0)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &sArr[i]);
        memset(maxSegSum, 0, sizeof(maxSegSum));
        memset(maxInverseSegSum, 0, sizeof(maxInverseSegSum));
        getMaxSegSum(sArr, maxSegSum, n);
        getMaxInverseSum(sArr, maxInverseSegSum, n);

        int result = 0x80000000;
        for (int i = 0; i < n - 1; ++i)
        {
            result = getMax(result, maxSegSum[i] + maxInverseSegSum[i + 1]);
        }
        printf("%d\n", result);
    }
    return 0;
}
