#include <stdio.h>
#include <stdlib.h>

int a[500005];

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int n,i,j,cnt;
    while(scanf("%d",&n)&&n)
    {
        cnt=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    //while(1);
  //system("PAUSE");	
  return 0;
}
