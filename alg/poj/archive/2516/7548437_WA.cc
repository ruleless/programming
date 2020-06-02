#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char str[105][105];
int node[105][105],w[105][105],n,lx[105],ly[105],link[105];
bool visx[105],visy[105];
bool Find(int a)
{
    visx[a]=true;
    int j;
    for(j=1;j<=n;j++)
    {
        if(!visy[j]&&lx[a]+ly[j]==w[a][j])
        {
            visy[j]=true;
            if(link[j]<0||Find(link[j]))
            {
                link[j]=a;
                return true;
            }
        }
    }
    return false;
}
void km()
{
    int i,j,k;
    memset(link,-1,sizeof(link));
    for(i=1;i<=n;i++)
    {
        ly[i]=0;
        lx[i]=0;
        for(j=1;j<=n;j++)
            lx[i]=max(lx[i],w[i][j]);
    }
    for(k=1;k<=n;k++)
    {
        memset(visx,0,sizeof(visx));
        memset(visy,0,sizeof(visy));
        while(!Find(k))
        {
            int d=1<<30;
            for(i=1;i<=k;i++)
                if(visx[i])
                    for(j=1;j<=n;j++)
                        if(!visy[j])
                            d=min(d,lx[i]+ly[j]-w[i][j]);
            for(i=1;i<=k;i++)
                if(visx[i])
                    lx[i]-=d;
            for(i=1;i<=n;i++)
                if(visy[i])
                    ly[i]+=d;
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
        }
    }
    k=0;
    for(i=1;i<=n;i++)
        k+=lx[i]+ly[i];
    printf("%d\n",-k);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,h,ww,l;
    while(scanf("%d%d",&h,&ww),h+ww)
    {
        memset(node,0,sizeof(node));
        int cntm=0,cnth=0;
        for(i=0;i<h;i++)
            scanf("%s",str[i]);
        for(i=0;i<h;i++)
            for(j=0;j<ww;j++)
            {
                if(str[i][j]=='m')
                    node[i][j]=++cntm;
                if(str[i][j]=='H')
                    node[i][j]=++cnth;
            }
        n=cntm;
        //printf("%d %d\n",cntm,cnth);
        for(i=0;i<h;i++)
        {
            for(j=0;j<ww;j++)
            {
                if(str[i][j]=='m')
                {
                    for(k=0;k<h;k++)
                    {
                        for(l=0;l<ww;l++)
                        {
                            if(str[k][l]=='H')
                                w[node[i][j]][node[k][l]]=-abs(k-i)-abs(l-j);
                        }
                    }
                }
            }
        }
        km();
    }
    //while(1);
    return 0;
}
