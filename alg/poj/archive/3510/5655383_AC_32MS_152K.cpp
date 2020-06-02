#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

char s[1000];
int L;
bool END;

void translate()
{
  L = strlen(s);
  for (int i = 0 ; i < L ; ++i)
    if (s[i] == ' ') printf(" ");
    else if (i + 2 < L && s[i] == 'E' && s[i + 1] == 'O' && s[i + 2] == 'F')
      {
 END = 1;
 if (i) printf("\n");
 return;
      }
    else if (s[i] >= 'a' && s[i] <= 'z')
      if (i < L - 1 && s[i] == 'd' && s[i + 1] == 'd')
 {
   printf("p");++i;
 }
      else if (i < L - 1 && s[i] == 'e' && s[i + 1] == 'i' && (!i || s[i - 1] != 'c'))
 {
   printf("ie");++i;
 }
      else if (i + 3 < L && s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'k')
 {
   printf("floyd");i += 3;
 }
      else printf("%c" , s[i]);
  printf("\n");
}

int main()
{
  END = 0;
  while (!END && gets(s))
      translate();
}


