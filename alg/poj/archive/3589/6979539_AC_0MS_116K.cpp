#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char a[6],b[6];
    int i,j,m,k,visit[6],t;
    scanf("%d",&t);
    while(t--)
    {
        m=0;
        k=0;
        scanf("%s%s",a,b);
        for(i=0;i<4;i++)
        {
            if(a[i]==b[i])
            {
                m++;
            }
        }
        memset(visit,0,sizeof(visit));
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(i!=j&&!visit[j])
                {
                    if(a[i]==b[j])
                    {
                        k++;
                        visit[j]=1;
                    }
                }
            }
        }
        printf("%dA%dB\n",m,k);
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
