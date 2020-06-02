#include <stdio.h>
#include <stdlib.h>

char s[200][200];
int visit[200][200];

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    int flag,i,j,m,n,cnt=0;
    memset(visit,0,sizeof(visit));
    scanf("%d%d",&m,&n);
    flag=0;
    i=1;j=0;
    while(1)
    {
        if(flag==0)
        {
            j++;
            if(j<=n&&!visit[i][j])
            {
                visit[i][j]=1;
                s[i][j]=(char)((int)('A')+(cnt++)%26);
            }
            else
            {
                flag=1;j--;
                if(i==m||visit[i+1][j])
                    break;
            }
        }
        else if(flag==1)
        {
            i++;
            if(i<=m&&!visit[i][j])
            {
                visit[i][j]=1;
                s[i][j]=(char)((int)('A')+(cnt++)%26);
            }
            else
            {
                flag=2;
                i--;
                if(j==1||visit[i][j-1])
                    break;
            }
        }
        else if(flag==2)
        {
            j--;
            if(j>=1&&!visit[i][j])
            {
                visit[i][j]=1;
                s[i][j]=(char)((int)('A')+(cnt++)%26);
            }
            else
            {
                flag=3;
                j++;
                if(i==1||visit[i-1][j])
                    break;
            }   
        }
        else if(flag==3)
        {
            i--;
            if(!visit[i][j])
            {
                visit[i][j]=1;
                s[i][j]=(char)((int)('A')+(cnt++)%26);
            }
            else
            {
                flag=0;
                i++;
                if(visit[i][j+1])
                    break;
            }
        }
    }
    for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("   %c",s[i][j]);
            }
            printf("\n");
        }
  
  //system("PAUSE");	
  //while(1);
  return 0;
}
