#include<iostream>
using namespace std;

const int N = 1000000;

int f[N + 20] , h[N + 20];
bool prime[N + 20] , squre[N + 20];

void ff()
{
   int T,i,j;
   memset(squre , 0 , sizeof(squre));
   memset(prime , 0 , sizeof(prime));
   for (i = 2 ; i <= N ; ++i)
       if (!prime[i])
       {
           j = i * 2;
           while (j <= N)
               prime[j] = 1, j += i;
       }
   squre[2] = 1;
   for (i = 1 ; i < 1000 ; ++i)
       for (j = i + 1 ; j < 1000 ; j += 2)
       {
           T = i * i + j * j;
           if (T < N) squre[T] = 1;
           else break;
       }
   f[0] = f[1] = h[0] = h[1] = 0;    
   for (i = 2 ; i <= N ; ++i)
       if (!prime[i]) 
       {
           f[i] = f [i - 1] + 1;
           if (squre[i]) h[i] = h [i - 1] + 1;
           else h[i] = h[i - 1];
       }
       else f[i] = f[i - 1] , h[i] = h[i - 1];
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n , m , N , M;
    ff();
    while (2 == scanf("%d %d" , &n , &m) && (n != -1 || m != -1))
    {
        N = (1>n)?1:n , M = (1>m)?1:m;
        printf("%d %d %d %d\n" , n , m , f[M] - f[N - 1] , h[M] - h[N - 1]);
    }
    return 0;
}
