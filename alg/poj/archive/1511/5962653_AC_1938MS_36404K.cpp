#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000010;
const int inf = INT_MAX;
typedef struct  
{
	int next, v, cost;
}Edge;

Edge e[MAXN], oppe[MAXN];
int assis[MAXN], oppassis[MAXN];
int dist[MAXN];
bool hash[MAXN];
int P, Q;

__int64 SPFA(int ass[], Edge ee[])
{
	queue <int> QQ;
	int first, i;
	first = 1;
	for (i = 1; i <= P; ++i)
	{
		hash[i] = false;
		dist[i] = inf;
	}
	dist[first] = 0;
	hash[first] = true;
	QQ.push(first);
	while (!QQ.empty())
	{
		first = QQ.front();
		QQ.pop();
		hash[first] = false;

		for (i = ass[first]; i != -1; i = ee[i].next)
		{
			if (ee[i].cost + dist[first] < dist[ee[i].v])
			{
				dist[ee[i].v] = ee[i].cost + dist[first];
				if (!hash[ee[i].v])
				{
					hash[ee[i].v] = true;
					QQ.push(ee[i].v);
				}
			}
			
		}
	}
	__int64 sum = 0;
	for (i = 1; i <= P; ++i)
	{
		sum += dist[i];
	}
	return sum;
}

void f()
{
	memset(assis, -1, sizeof(assis));
	memset(oppassis, -1, sizeof(oppassis));
	scanf("%d %d", &P, &Q);
	int i;
	for (i = 0; i < Q; ++i)
	{
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		e[i].v = y;
		e[i].cost = cost;
		e[i].next = assis[x];
		assis[x] = i;
		
		oppe[i].v = x;
		oppe[i].cost = cost;
		oppe[i].next = oppassis[y];
		oppassis[y] = i;
	}
	__int64 result = SPFA(assis, e) + SPFA(oppassis, oppe);

	printf("%I64d\n", result);
}


int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		f();
	}
	return 0;
}
