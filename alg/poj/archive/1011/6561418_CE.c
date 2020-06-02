#include <stdio.h>
#include <stdlib.h>

int n;
int a[80],visit[80],tmp,len;

int dfs(int k)
{
    int i;
    if(tmp==len)
    {
        return 1;
    }
    for(i=k+1;i<n;i++)
    {
        if(!visit[i]&&tmp+a[i]<=len)
        {
            tmp+=a[i];
            visit[i]=1;
            if(dfs(i))
            {
                return 1;
            }
            tmp-=a[i];
            visit[i]=0;
        }
    }
    return 0;
}

int f()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            tmp=a[i];
            if(!dfs(i))
            {
                return 0;
            }
        }
    }
    return 1;
}

int cmp(const void*a,const void* b)
{
    return -( *(int*)a-*(int*)b );
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d",&n)&&n)
    {
        int flag=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        /*for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");*/
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
        }      
        for(len=a[0];len<=sum/2;len++)
        {
            if(sum%len==0)
            {
                memset(visit,0,sizeof(visit));
                if(f())
                {
                    printf("%d\n",len);
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("%d\n",sum);
        }
    }
    //while(1);
  
  //system("PAUSE");	
  return 0;
}
