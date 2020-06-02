#include<iostream>
using namespace std;
char a[1000001],b[1000001];
int main() {
  //  freopen("in.txt","r",stdin);
    int len,i,j,t,count=1;
    char m;
    while(scanf("%s",a),strcmp(a,"0")!=0) {
        
        len=strlen(a);

        b[len-1]=a[len-1];
        for(i=len-2;i>=0;i--) {
            t=a[i]-b[i+1];
            if(t<0) {t+=10;a[i-1]--;}
            b[i]=t+48;
        }
        printf("%d. ",count++);
        b[len]='\0';
        if(b[0]<='0'||b[0]>'9') puts("IMPOSSIBLE");
        else puts(b);
        
    }
    return 0;
}


