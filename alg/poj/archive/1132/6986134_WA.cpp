#include <cstdlib>
#include <iostream>

using namespace std;

char a[40][40];
char order[1000];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i,j,t,x,y;
    char pre,now;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%s",&x,&y,order);
        
        int len=strlen(order);
        for(i=1;i<=32;i++)
        {
            for(j=1;j<=32;j++)
            {
                a[i][j]='.';
            }
        }
        pre='0';
        for(i=0;i<len-1;i++)
        {
            
            now=order[i];
            if(now=='E')
            {
                x++;
                a[x][y]='X';
                //printf("%d %d\n",x,y);
            }else if(now=='N')
            {
                y++;
                a[x+1][y]='X';
                //printf("%d %d\n",x+1,y);
            }else if(now=='W')
            {
                x--;
                a[x+1][y+1]='X';
                //printf("%d %d\n",x+1,y+1);
                
            }else if(now=='S')
            {
                y--;
                a[x][y+1]='X';
                //printf("%d %d\n",x,y+1);
                
            }
        }
        for(i=32;i>=1;i--)
        {
            for(j=1;j<=32;j++)
            {
                //printf("Yes");
                printf("%c",a[j][i]);
            }
            printf("\n");
        }
        printf("\n");
        //printf("%c\n",a[5][1]);
        //printf("Yes");
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
