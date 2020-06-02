#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char str[100005][20],dic[100005][20];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,k,n,cnt,pre;
    n=0;
    while(scanf("%s",str[n++])!=EOF);
    cnt=0;
    pre=0;
    for(i=0;i<n;i++)
    {
        if(cnt==0)
        {
            pre=0;
            strcpy(dic[cnt++],str[i]);
            printf("%s\n",dic[0]);
        }
        else if(str[i][0]!=dic[0][0])
        {
            pre=0;
            cnt=0;
            strcpy(dic[cnt++],str[i]);
            printf("%s\n",str[i]);
        }
        else
        {
            for(j=0;j<strlen(str[i])&&j<strlen(dic[cnt-1])&&str[i][j]==dic[cnt-1][j];j++);
            if(j>pre)
            {
                j=++pre;
            }
            while(j--)
            {
                printf(" ");
            }
            strcpy(dic[cnt++],str[i]);
            printf("%s\n",str[i]);
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
