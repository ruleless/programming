#include<iostream>
using namespace std;

int n,m,a[11000],f[11000],ca;


int main()
{
//    freopen("in.txt","r",stdin);
    int i;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&m,&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        f[0]=0;
        for(i=1;i<=n;i++)
        {
             f[i]=1000000000;
            int j=i;
            int sum=0;
            while ((j>0)&&(sum+a[j]<=m))
            {
                sum=sum+a[j];
                j--;
                if (f[j]+(m-sum)*(m-sum)<f[i])
                    f[i]=f[j]+(m-sum)*(m-sum);
                sum++;
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
