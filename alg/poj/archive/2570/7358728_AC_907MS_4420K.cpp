#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct route
{
    int all[26];
}
map[210][210];
int main()
{
    int i,j,k,h,nodenum,from,to,flag;
    char input[30];
    while (scanf("%d",&nodenum) != EOF && nodenum)
    {
        for (i = 1;i <= nodenum;i++)
            for (j = 1;j <= nodenum;j++)
                for (k = 0;k < 26;k++)
                    map[i][j].all[k] = 0;
        while (scanf("%d %d ",&from,&to) != EOF && (from || to))
        {
            scanf("%s",input);
            for (i = 0;i < strlen(input);i++)
                map[from][to].all[input[i]-'a'] = 1;
        }
        for (k = 1;k <= nodenum;k++)
            for (i = 1;i <= nodenum;i++)
                for (j = 1;j <= nodenum;j++)
                {
                    for (h = 0;h < 26;h++)
                        if (map[i][k].all[h] == 1 && map[k][j].all[h] == 1)
                            map[i][j].all[h] = 1;
                }
        while (scanf("%d %d",&from,&to) != EOF && (from || to))
        {
            for (i = 0,flag = 0;i < 26;i++)
                if (map[from][to].all[i] == 1)
                {
                    printf("%c",i+'a');
                    flag = 1;
                }
            if (flag == 0)
                printf("-");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
