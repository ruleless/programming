#include <cstdlib>
#include <iostream>

using namespace std;

int a[25][25];

int f(int i,int j,int& ii,int& jj)
{
    int flag=a[i][j],k,l,yes;
    if(flag==0)
    {
        return 0;
    }
    l=j;
    yes=1;
    for(k=i;k<=i+4;k++)
    {
        if(k>=1&&k<=19&&l>=1&&l<=19)
        {
            if(a[k][l]!=flag)
            {
                yes=0;
                break;
            }
        }
        else
        {
            yes=0;
            break;
        }
        l--;
    }
    if(yes)
    {
        if(k>=1&&k<=19&&l>=1&&l<=19)
        {
            if(a[k][l]!=flag)
            {
                ii=k-1;
                jj=l+1;
                return flag;
            }
        }
        else
        {
            ii=k-1;
            jj=l+1;
            return flag;
        }
    }
    l=j;
    yes=1;
    for(k=i;k<=i+4;k++)
    {
        if(k>=1&&k<=19&&l>=1&&l<=19)
        {
            if(a[k][l]!=flag)
            {
                yes=0;
                break;
            }
        }
        else
        {
            yes=0;
            break;
        }
        l++;
    }
    if(yes)
    {
        if(k>=1&&k<=19&&l>=1&&l<=19)
        {
            if(a[k][l]!=flag)
            {
                ii=i;
                jj=j;
                return flag;
            }
        }
        else
        {
            ii=i;
            jj=j;
            return flag;
        }
    }
    yes=1;
    for(l=j;l<=j+4;l++)
    {
        if(l>=1&&l<=19)
        {
            if(a[i][l]!=flag)
            {
                yes=0;
                break;
            }
        }
        else
        {
            yes=0;
            break;
        }
    }
    if(yes)
    {
        if(l>=1&&l<=19)
        {
            if(a[i][l]!=flag)
            {
                ii=i;
                jj=j;
                return flag;
            }
        }
        else
        {
            ii=i;
            jj=j;
            return flag;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int t,i,j,ii,jj,res,flag;
    scanf("%d",&t);
    while(t--)
    {
        for(i=1;i<=19;i++)
        {
            for(j=1;j<=19;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        res=0;
        flag=0;
        for(i=1;i<=19;i++)
        {
            for(j=1;j<=19;j++)
            {
                res=f(i,j,ii,jj);
                if(res)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(res!=0)
        {
            printf("%d\n",res);
            printf("%d %d\n",ii,jj);
        }
        else
        {
            printf("%d\n",res);
        }
    }
    //while(1);
    //system("PAUSE");
    return EXIT_SUCCESS;
}
