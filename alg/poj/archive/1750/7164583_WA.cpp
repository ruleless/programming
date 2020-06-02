#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    char pre[15],cur[15];
    int dot,i,j,k;
    scanf("%s",pre);
    dot=0;
    printf("%s\n",pre);
    while(scanf("%s",cur)!=EOF)
    {
        for(j=0;j<strlen(cur)&&j<strlen(pre)&&pre[j]==cur[j];j++);
        if(j>dot)
        {
            dot++;
        }
        else
        {
            dot=j;
        }
        j=dot;
        while(j--)
        {
            printf(".");
        }
        printf("%s\n",cur);
        strcpy(pre,cur);
    }
   // while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
