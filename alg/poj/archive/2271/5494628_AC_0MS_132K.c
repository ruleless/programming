#include<stdio.h>
#include<string.h>
void main()
{
 char t[81];
 int l,m,j=0,len=0;
  while(scanf("%s",t)==1)
  {
      if(t[0]=='<')
      {
       if(t[1]=='b')
       {len=0;printf("\n");}
       else
       {
	if(len!=0)
	 printf("\n");
	len=0;
	for(j=0;j<80;j++)
	 printf("-");
	printf("\n");
       }
      }//1th if
      else
      {
       len=len+1+strlen(t);
       if(len>80)
       {printf("\n");
	len=strlen(t);
       }
       printf("%s ",t);
       }
 }
 printf("\n");
}
