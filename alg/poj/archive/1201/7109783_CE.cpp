#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX 60000
#define MAXINT 1000000

struct EDGE{
int st,ed,val;
}edge[MAX];

int dis[MAX],n,min,max;

int bellman_ford()
{
int i , k;
for(i = min ; i <= max ; i++ )
   dis[i] = -MAXINT ;
dis[min] = 0 ;
bool over;
for(k = 0 ; k <= max - min ; k ++ )
{
   over = true ;

   for(i = 0 ; i < n ; i ++ )
    if(dis[edge[i].st] != -MAXINT && dis[edge[i].st] + edge[i].val > dis[edge[i].ed] )
    {
     dis[edge[i].ed] = dis[edge[i].st] + edge[i].val ;
     over = false;
    }

   for(i=min;i<max;i++)
    if( dis[i] != -MAXINT && dis[i] > dis[i+1] )
    {
     dis[i+1] = dis[i] ;
     over = false ;
    }

   for(i = max ; i > min ; i --)
    if(dis[i] != -MAXINT && dis[i]-1 > dis[i-1])
    {
     dis[i-1] = dis[i]-1 ;
     over = false ;
    }

   if(over)
    break;
}
return dis[max];
}

int main()
{
int i;
while(scanf("%d",&n)!=EOF)
{
   min=MAXINT;
   max=0;
   for(i=max;i<n;i++)
   {
    scanf("%d%d%d",&edge[i].st,&edge[i].ed,&edge[i].val);   ///   1<= ci <= bi - ai + 1
    edge[i].ed++;
    if( edge[i].ed > max )
     max = edge[i].ed ;
    if( edge[i].st < min )
     min = edge[i].st;
   }
   printf("%d\n",bellman_ford());
}
return 0;
}
