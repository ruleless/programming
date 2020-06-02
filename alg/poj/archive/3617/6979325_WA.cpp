#include <cstdlib>
#include <iostream>

using namespace std;
char str[100],res[100];

void f(int beg,int end,int& flag)
{
    while(end>=beg&&str[beg]==str[end])
    {
        beg++;end--;
    }
    if(beg>end)
    {
        flag=0;
        return;
    }
    if(str[beg]<str[end])
    {
        flag=0;
    }
    else
    {
        flag=1;
    }
}

int main(int argc, char *argv[])
{
    int n,i,k,beg,end,j;
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char temp[6];
        scanf("%s",temp);
        str[i]=temp[0];
    }
    beg=0;
    end=n-1;
    k=1;
    while(end>=beg)
    {
        if(str[beg]>str[end])
        {
            res[k++]=str[end];
            end--;
        }
        else if(str[beg]<str[end])
        {
            res[k++]=str[beg];
            beg++;
        }
        else
        {
            int flag;
            f(beg,end,flag);
            if(flag==0)
            {
                res[k++]=str[beg];
                beg++;
            }
            else
            {
                res[k++]=str[end];
                end--;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i%80==0)
        {
            printf("\n");
        }
        printf("%c",res[i]);
    }
    if(n%80!=0)
    {
        printf("\n");
    }
   // while(1);
    return EXIT_SUCCESS;
}
