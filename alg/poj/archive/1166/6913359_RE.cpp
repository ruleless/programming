#include <cstdlib>
#include <iostream>

using namespace std;

int a[11],b[11],res[11];

void add(int k,int t)
{
    if(k==1)
    {
        b[1]=(b[1]+t)%4;
        b[2]=(b[2]+t)%4;
        b[4]=(b[4]+t)%4;
        b[5]=(b[5]+t)%4;
    }
    else if(k==2)
    {
        b[1]=(b[1]+t)%4;
        b[2]=(b[2]+t)%4;
        b[3]=(b[3]+t)%4;
    }
    else if(k==3)
    {
        b[2]=(b[2]+t)%4;
        b[3]=(b[3]+t)%4;
        b[5]=(b[5]+t)%4;
        b[6]=(b[6]+t)%4;
    }
    else if(k==4)
    {
        b[1]=(b[1]+t)%4;
        b[4]=(b[4]+t)%4;
        b[7]=(b[7]+t)%4;
    }
    else if(k==5)
    {
        b[2]=(b[2]+t)%4;
        b[4]=(b[4]+t)%4;
        b[5]=(b[5]+t)%4;
        b[6]=(b[6]+t)%4;
        b[8]=(b[8]+t)%4;
    }
    else if(k==6)
    {
        b[3]=(b[3]+t)%4;
        b[6]=(b[6]+t)%4;
        b[9]=(b[9]+t)%4;
    }
    else if(k==7)
    {
        b[4]=(b[4]+t)%4;
        b[5]=(b[5]+t)%4;
        b[7]=(b[7]+t)%4;
        b[8]=(b[8]+t)%4;
    }
    else if(k==8)
    {
        b[7]=(b[7]+t)%4;
        b[8]=(b[8]+t)%4;
        b[9]=(b[9]+t)%4;
    }
    else if(k==9)
    {
        b[5]=(b[5]+t)%4;
        b[6]=(b[6]+t)%4;
        b[8]=(b[8]+t)%4;
        b[9]=(b[9]+t)%4;
    }
}

int f()
{
    int i;
    for(i=1;i<=9;i++)
    {
        if(b[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int x[10],i,k=1<<30,temp;
    for(x[1]=0;x[1]<4;x[1]++)
    {
        for(x[2]=0;x[2]<4;x[2]++)
        {
            for(x[3]=0;x[3]<4;x[3]++)
            {
                for(x[4]=0;x[4]<4;x[4]++)
                {
                    for(x[5]=0;x[5]<4;x[5]++)
                    {
                        for(x[6]=0;x[6]<4;x[6]++)
                        {
                            for(x[7]=0;x[7]<4;x[7]++)
                            {
                                for(x[8]=0;x[8]<4;x[8]++)
                                {
                                    for(x[9]=0;x[9]<4;x[9]++)
                                    {
                                        temp=0;
                                        memcpy(b,a,sizeof(a));
                                        for(i=1;i<=9;i++)
                                        {
                                            add(i,x[i]);
                                            temp+=x[i];
                                        }
                                        if(f()&&temp<k)
                                        {
                                            //printf("Yes");
                                            k=temp;
                                            for(i=1;i<=9;i++)
                                            {
                                                res[i]=x[i];
                                            }
                                        }
                                    }
                                }                 
                            }                           
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
 //   freopen("in.txt","r",stdin);
    int i,tt[11],cnt=0;
    for(i=1;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    solve();
    for(i=1;i<10;i++)
    {
        if(res[i]!=0)
        {
            while(res[i]--)
            {
                tt[cnt++]=i;
            }
        }
    }
    for(i=0;i<cnt-1;i++)
    {
        printf("%d ",tt[i]);
    }
    printf("%d\n",tt[cnt-1]);
 //   while(1);
  //  system("PAUSE");
    return EXIT_SUCCESS;
}
