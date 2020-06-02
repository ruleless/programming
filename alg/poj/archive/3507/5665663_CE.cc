#include<iostream>
using namespace std;
int th[6];
int main() {
 //   freopen("in.txt","r",stdin);
    double a;
    char t[6];
    int i,j,temp;
    while(scanf("%d%d%d%d%d%d",&th[0],&th[1],&th[2],&th[3],&th[4],&th[5])) {
    //    if(th[0]==th[1]==th[2]==th[3]==th[4]==th[5]==0) break;
         if(th[0]==0&&th[1]==0&&th[2]==0&&th[3]==0&&th[4]==0&&th[5]==0) break;
    a=0.0;
    for(i=0;i<6;i++)
        for(j=i+1;j<6;j++)
            if(th[i]>th[j]) {temp=th[i];th[i]=th[j];th[j]=temp;}
        for(i=1;i<5;i++)
            a+=th[i]+0.0;
        a/=4;
    
        sprintf(t,"%.6f",a);
        for(i=5;i>=0;i--)
            if(t[i]=='0') t[i]='\0';
            else break;
        int len=strlen(t);
        if(t[len-1]=='.') t[len-1]='\0';
    //    for(
        printf("%s\n",t);
//        printf("%f\n",a);

    }
    return 0;
}
