#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000

int parent[N];

int Find(int a)
{
        if (parent[a] < 0)
                return a;

        int root = Find(parent[a]);
        parent[a] = root; // 路径压缩
        return root;
}

void Union(int a, int b)
{
        int rootA = Find(a);
        int rootB = Find(b);
        if (rootA == rootB)
                return;

        if (parent[rootA] < parent[rootB])
        {
                parent[rootA] += parent[rootB];
                parent[rootB] = rootA;
        }
        else
        {
                parent[rootB] += parent[rootA];
                parent[rootA] = rootB;
        }
}

int main(int argc, char *argv[])
{
        // freopen("in.txt", "r", stdin);

        int s, t;
        int maxNode = 0;
        bool bIsTree = true;
        bool bNewCase = true;
        int casecount = 0;
        while (scanf("%d%d", &s, &t) != EOF)
        {
                if (s < 0 || t < 0)
                        break;
                if (s == 0 && t == 0)
                {
                        if (bIsTree)
                        {
                                int root = -1;
                                for (int v = 1; v <= maxNode; ++v)
                                {
                                        if (root < 0)
                                        {
                                                root = Find(v);
                                        }
                                        else if (root != Find(v))
                                        {
                                                bIsTree = false;
                                                break;
                                        }
                                }
                        }

                        if (bIsTree)
                        {
                                printf("Case %d is a tree.\n", ++casecount);
                        }
                        else
                        {
                                printf("Case %d is not a tree.\n", ++casecount);
                        }
                        maxNode = 0;
                        bIsTree = true;
                        bNewCase = true;
                        continue;
                }

                if (bNewCase)
                        memset(parent, -1, sizeof(parent));
                bNewCase = false;

                if (bIsTree)
                {
                        if (s > maxNode)
                                maxNode = s;
                        if (t > maxNode)
                                maxNode = t;
                        if (Find(s) == Find(t))
                        {
                                bIsTree = false;
                        }
                        else
                        {
                                Union(s, t);
                        }
                }
        }
        return (0);
}
