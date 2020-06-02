#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    char d[50],y[10],m[10],h[10];
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",d);
        for(i=0;i<4;i++)
        {
            y[i]=d[i]; 
        }
        y[i]='\0';
        for(i=5;i<10;i++)
        {
            m[i-5]=d[i];
        }
        m[i-5]='\0';
        for(i=14;i<19;i++)
            h[i-14]=d[i];
        h[i-14]='\0';
        n=(int)(d[11]-'0')*10+(int)(d[12]-'0');
        if(n>=12)
        {
            if(n==12)
                printf("%s/%s-%d:%spm\n",m,y,n,h);
            else
                printf("%s/%s-%d:%spm\n",m,y,n-12,h);
        }
        else
        {
            if(n<10)
            {
                if(n==0)
                {
                    n=12;
                    printf("%s/%s-%d:%sam\n",m,y,n,h);
                }
                else
                    printf("%s/%s-0%d:%sam\n",m,y,n,h);
            }
            else
                printf("%s/%s-%d:%sam\n",m,y,n,h);
            
        }
    }
  
  //system("PAUSE");	
  //while(1);
  return 0;
}
