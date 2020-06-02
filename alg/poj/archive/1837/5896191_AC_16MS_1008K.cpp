#include <iostream>
#include <stdlib.h>

using namespace std;

int s[21][10000],mid=5000;

int main(int argc, char *argv[])
{
int hook[21],value[21],c,g,i,j,k;
while(scanf("%d%d",&c,&g)!=EOF){
      memset(s,0,sizeof(s));
      for(i=1;i<=c;i++){
          scanf("%d",&hook[i]);
          }
      for(i=1;i<=g;i++){
          scanf("%d",&value[i]);
          }
      for(i=1;i<=c;i++){
          s[1][mid+value[1]*hook[i]]++;
          }
      for(i=2;i<=g;i++){
          for(j=1;j<=c;j++){
              for(k=0;k<12000;k++){
                  if(s[i-1][k]==0) continue;
                  s[i][k+value[i]*hook[j]]+=s[i-1][k];
                  }
              }
          }
      printf("%d\n",s[g][mid]);
      }
system("PAUSE");    
return 0;
}