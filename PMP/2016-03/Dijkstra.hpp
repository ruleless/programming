#ifndef __DIJKSTRA_HPP__
#define __DIJKSTRA_HPP__

#include "AdjList.hpp"

namespace alg
{
template<class T, int MaxV>
void dijkstra(int n, SEdge<T>* v[], int s, T *dist)
{
	bool visited[MaxV];
	memset(visited, false, sizeof(visited));

	for (SEdge<T> *e = v[s]; e; e = e->next)
		dist[e->to] = e->w;

	visited[s] = true;
	int looptimes = n-2; looptimes = looptimes > 0 ? looptimes : 0;
	while (looptimes--)
	{
		int u = 0;
		while (visited[u]) ++u;
		for (int i = u+1; i < n; ++i)
		{
			if (!visited[i] && dist[i] < dist[u])
				u = i;
		}
		
		for (SEdge<T> *e = v[u]; e; e = e->next)
		{
			if (!visited[e->to] && dist[u]+e->w < dist[e->to])
				dist[e->to] = dist[u]+e->w;
		}
	}
}
}

#endif // __DIJKSTRA_HPP__
