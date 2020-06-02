#include <iostream>
using namespace std;
__int64 X, Y;
__int64 exp_gcd(__int64 a, __int64 b, __int64 &X, __int64 &Y)
{
     __int64 q, temp;
     if(b == 0)
     {
         q = a;
         X = 1;
         Y = 0;
         return q;
     }else
  {
        q = exp_gcd(b, a % b, X, Y);
        temp = X;
        X = Y;
        Y = temp - (a / b) * Y;
        return q;
  }
}
__int64 GCD(__int64 a, __int64 b)
{
     __int64 m = 1;
     while(m)
  {
        m = a%b;
        a = b;
        b = m;
  }
     return a;
}
__int64 x, y, m, n, l, A, B, C;
__int64 gcd; 
int main()
{
 while(scanf("%I64d%I64d%I64d%I64d%I64d", &x, &y, &m, &n, &l) != EOF)
 {
  A = n - m;
  B = l;
  C = x - y;

  gcd = GCD(A, B);
  if(C % gcd != 0)
  {
   printf("Impossible\n");
   continue;
  }
  A = A/gcd;
  B = B/gcd;
  C = C/gcd;

  exp_gcd(A, B, X, Y);
     X *= C;

  if(X < 0)
      X += ((-X/B) + 1) * B;
  else if(X > 0)
   X -= (X/B)*B;


  printf("%I64d\n", X);
 }
}
