#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define MAXN 10010

vector<int>  Tree[MAXN], query[MAXN];
int          Set[MAXN], num[MAXN],root[MAXN], ancestor[MAXN];
bool          visite[MAXN];
int n;

void initial()
{
    for( int i= 0; i<= n; ++i )
    Tree[i].clear(), num[i]= 1, query[i].clear();
    
    memset( root, false, sizeof(root) );
    memset( visite, false, sizeof(root) );
    memset( ancestor, 0, sizeof(ancestor) );
}

void  make_set( int u )
{
    Set[u]= u;
}

int find( int u )
{
    while( u!= Set[u] ) u= Set[u];
    
    return u;
}

void union_set( int u, int v )
{
    int a= find(u), b= find(v);
    
    if( num[a]> num[b] ) Set[b]= a;
    else     
    {
       Set[a]= b;
       if( num[a]== num[b] ) num[b]++;
    }
}

void l_c_a( int u )
{
    make_set( u );
    ancestor[u]= u;
    
    for( size_t i= 0; i< Tree[u].size(); ++i )
    {
        l_c_a( Tree[u][i] );
        
        union_set( u, Tree[u][i] );
        ancestor[ find(u) ]= u;
    }
    
    visite[u]= true;
    
    for( size_t i= 0; i< query[u].size(); ++i )
    if( visite[ query[u][i] ] )
    {
        printf("%d\n", ancestor[ find( query[u][i] ) ] );
        return;
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    
    while( test-- )
    {
        int a, b;
        scanf("%d",&n);
        
        initial();
        for( int i= 0; i< n- 1; ++i )
        {
            scanf("%d%d",&a,&b);
            
            Tree[a].push_back(b);
            root[b]= true;
        }
        
        scanf("%d%d",&a,&b);
        if( a== b ) query[a].push_back(a);
        else
        {
            query[a].push_back(b);
            query[b].push_back(a);
        }
        
        for( int i= 1; i<= n; ++i )
        if( !root[i] )
        {
            l_c_a(i);
            break;
        }
    }
    
    return 0;
}
