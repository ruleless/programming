#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 1000011
typedef struct Node 
{
char dic[12];
char str[12];
}BaBelfish;
BaBelfish T[MAX];
int cmp(const void * a,const void *b)
{
return strcmp(((BaBelfish *)a)->str,((BaBelfish *)b)->str);
}
int binary_search(char a[],int len)
{
int low=0;
int high=len-1;
while(low<=high)
{
   int mid=(low+high)/2;
   if(strcmp(T[mid].str,a)==0)
   {
    return mid;
   }
   else if(strcmp(T[mid].str,a)<0)
   {
    low=mid+1;
   }
   else
   {
    high=mid-1;
   }
}
return -1;
}
int main()
{
	//freopen("in.txt","r",stdin);
char a[12];
char b[12];
char c;
char d[12];
c=getchar();
int j=0;
int i=0;
while(c!='\n')
{
   j=0;
   while(c>='a'&&c<='z')
   {
   a[j++]=c;
   c=getchar();
   }
   a[j]='\0';
   while(c<'a'||c>'z')
   c=getchar();
   j=0;
   while(c>='a'&&c<='z')
   {
    b[j++]=c;
    c=getchar();
   }
   b[j]='\0';
   strcpy(T[i].dic,a);
   strcpy(T[i].str,b);
   i++;
   c=getchar();
}
qsort(T,i,sizeof(T[0]),cmp);
while(scanf("%s",d)!=EOF)
{
   int t=binary_search(d,i);
        if(t==-1)
    printf("eh\n");
   else
    printf("%s\n",T[t].dic);

}
return 0;

}