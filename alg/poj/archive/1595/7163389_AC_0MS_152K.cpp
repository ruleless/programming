//素数树 
#include<stdio.h>
#include<vector>
#include <iostream>

using namespace std;

#define N 2000
bool isprim[N+1];
void prim()
{
	int i,j;
    for (i=0;i<=N;i++)
        isprim[i]=true;
    isprim[0]=false;
    isprim[1]=false;
    for (i=2;i<=N/2;i++)
        if (isprim[i])
            for (j=2;i*j<=N;j++)
                    isprim[i*j]=false;
}

int a[1005];

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,n,cnt,c;
    prim();
    isprim[1]=1;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(isprim[i])
            {
                a[++cnt]=i;
            }
        }
        if(cnt%2==0)
        {
            if(2*c>=cnt)
            {
                printf("%d %d:",n,c);
                for(i=1;i<=cnt;i++)
                {
                    printf(" %d",a[i]);
                }
                printf("\n\n");
            }
            else
            {
                printf("%d %d:",n,c);
                for(i=(cnt-2*c)/2+1;i<=(cnt+2*c)/2;i++)
                {
                    printf(" %d",a[i]);
                }
                printf("\n\n");
            }
        }
        else
        {
            if(2*c-1>=cnt)
            {
                printf("%d %d:",n,c);
                for(i=1;i<=cnt;i++)
                {
                    printf(" %d",a[i]);
                }
                printf("\n\n");
            }
            else
            {
                printf("%d %d:",n,c);
                for(i=(cnt-2*c+1)/2+1;i<=(cnt+2*c-1)/2;i++)
                {
                    printf(" %d",a[i]);
                }
                printf("\n\n");
            }
        }
    }
    //while(1);
    return 0;
}
