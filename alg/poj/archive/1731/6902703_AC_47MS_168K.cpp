#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

char s[203];

void solve()
{
    int n=strlen(s);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    
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
