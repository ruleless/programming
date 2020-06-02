#include<iostream>
using namespace std;

struct node{
       int len,wei;
       };
struct node stick[20001];
        
bool flag[20001];

int cmp(const void*a,const void*b)
{
    if(((struct node*)a)->len==((struct node*)b)->len)
    {
        return -(((struct node*)a)->wei-((struct node*)b)->wei);
    }
    else
    {
        return ((struct node*)a)->len-((struct node*)b)->len;
    }
}
        
        

int main()
{
 //  freopen("in.txt","r",stdin);
    int t,n,i,j,k,sum,m,tt;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
                     memset(flag,0,sizeof(flag));
                     sum=0;
                     scanf("%d",&n);
                     for(j=0;j<n;j++)
                     {
                                     scanf("%d%d",&stick[j].len,&stick[j].wei);
                     }
                     qsort(stick,n,sizeof(struct node),cmp);
                     for(j=0;j<n;j++)
                     {
                                       tt=sum;
                                       m=j;
                                       if(flag[j]==false)
                                       {
                                       for(k=j+1;k<n;k++)
                                       if(stick[k].wei>stick[m].wei&&flag[k]==false&&stick[k].len>stick[m].len)
                                       {                                                                                                           
                                                                       flag[k]=true;
                                                                       if(m==j)
                                                                       sum++;
                                                                       m=k;
                                       }
                                       if(tt==sum)
                                       sum++;
                                       }
                     }
                     printf("%d\n",sum);
    }
    return 0;
}
                     
