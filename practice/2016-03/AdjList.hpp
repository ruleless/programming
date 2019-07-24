#ifndef __ADJLIST_H__
#define __ADJLIST_H__

namespace alg
{
template <class T>
struct SEdge
{
	int to;
	T w;

	SEdge *next;
};

template <class T, int MaxEdge>
class DynamicEdgeGenerator
{
  public:
    DynamicEdgeGenerator() {}

	SEdge<T>* newEdge()
	{
		return new SEdge<T>;
	}
	void delEdge(SEdge<T> *e)
	{
		delete e;
	}
  protected:
	~DynamicEdgeGenerator() {}
};

template <class T, int MaxEdge>
class StaticEdgeGenerator
{
  protected:
	int edgecount;
	SEdge<T> edgeStorage[MaxEdge];
  public:
    StaticEdgeGenerator() : edgecount(0) {}

	SEdge<T>* newEdge()
	{
		return &edgeStorage[edgecount++];
	}

	void delEdge(SEdge<T> *e)
	{
	}
  protected:
	~StaticEdgeGenerator() {}
};

template<int N,
		 int MaxEdge=N*N,
		 class T = int,
		 template<class, int> class EdgeGen=StaticEdgeGenerator>
class AdjList : public EdgeGen<T, MaxEdge>
{
  public:
	typedef SEdge<T> TEdge;
	TEdge* v[N];

    AdjList()
	{
		memset(v, 0, sizeof(v));
	}
	~AdjList()
	{
		for (int i = 0; i < N; ++i)
		{
			for (TEdge *e = v[i]; e ; )
			{
				TEdge *prev = e;
				e = e->next;
				this->delEdge(prev);
			}
		}
	}

	void addEdge(int from, int to, T w)
	{
		TEdge *newE = this->newEdge();
		newE->to = to;
		newE->w = w;
		newE->next = v[from];
		v[from] = newE;
	}
};
}

#endif
