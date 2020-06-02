#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

char s[203];

void solve()
{
    int n=strlen(s);
    do
    {
        printf("%s\n",s);
    }while(next_permutation(s,s+n));
}

int main(int argc, char *argv[])
{
    scanf("%s",s);
    solve();
   // system("PAUSE");
    return EXIT_SUCCESS;
}
