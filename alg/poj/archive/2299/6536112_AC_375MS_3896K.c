#include <stdio.h>
#include <stdlib.h>

int a[500005];
int tmp[500005];
int n;
__int64 cnt;

void merge(int beg,int mid,int end)
{
    int i=beg,j=mid+1,k=beg;
    while(i<=mid&&j<=end)
    {
        if(a[i]>a[j])
        {
            cnt+=mid+1-i;
            tmp[k++]=a[j++];
        }
        else
        {
            tmp[k++]=a[i++];
        }
    }
    while(i<=mid)
    {
        tmp[k++]=a[i++];
    }
    while(j<=end)
    {
        tmp[k++]=a[j++];
    }
    for(i=beg;i<=end;i++)
    {
        a[i]=tmp[i];
    }
}

void mergeSort(int beg,int end)
{
    if(beg!=end)
    {
        int mid=(beg+end)/2;
        mergeSort(beg,mid);
        mergeSort(mid+1,end);
        merge(beg,mid,end);
    }
}

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        cnt=0;
        mergeSort(0,n-1);
        printf("%I64d\n",cnt);
    }
   //while(1);
  //system("PAUSE");	
  return 0;
}
