#include <stdio.h>
#include <stdlib.h>

int N;
int a[1000];

int main(int argc, char *argv[])
{
    scanf("%d",&N);
    int i,j,k=1,sum=2;
    a[1]=2;
    while(N-sum>a[k])
    {
        a[++k]=a[k-1]+1;
        sum+=a[k];
    }
    j=N-sum;
    for(i=k;i>=1;i--)
    {
        a[i]++;
        j--;
        if(j==0)
        {
            break;
        }
    }
    a[k]+=j;
    for(i=1;i<=k;i++)
    {
        printf("%d ",a[i]);
    }
    //printf("%d\n",a[k]);
  //system("PAUSE");	
  return 0;
}
