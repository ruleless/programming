#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 30005

struct Node
{
   char s[32];    
   char t[32];
}p[M];

int a[M][2];     

int cmp(const void *p1,const void *p2)
{
    Node *c = (Node *)p1;
    Node *d = (Node *)p2;
    if(strcmp(c->s,d->s)==0)
		return strcmp(c->t,d->t);
	else
	return strcmp(c->s,d->s);
}

int main()
{
   int j = 0;
   int i,k,r,count,count1;
   //freopen("in.txt","r",stdin);
   while(scanf("%s",p[j].s)!=EOF)
   { 
   k = strlen(p[j].s);
   strcpy(p[j].t,p[j].s);
      sort(p[j].s,p[j].s+k);
   j++;
   }
   qsort(p,j,sizeof(p[0]),cmp);
   
   count1 = 0;
   for(i = 0; i < j;)
   { 
    count = 1;
    a[count1][0] = i;
           while(strcmp(p[i].s,p[i+1].s)==0)
    {
        i++;
     count++;
    }
    a[count1][1] = count;
           count1++;
    i++;
   }
   
   k = count1<5?count1:5;
          while(k--)
   { 
   int min = 0;
   j = 0;
          for(r = 0; r<count1;r++)
   {
        if(min<a[r][1]||(min==a[r][1]&&strcmp(p[a[r][0]].t,p[a[j][0]].t)<0)) 
     {
      min = a[r][1];
      j = r;
     }
   }
   a[j][1] = 0;
   printf("Group of size %d: ",min);
   while(min--)
   {
    if(min+1==a[j][0]||strcmp(p[a[j][0]-1].t,p[a[j][0]].t))   
         printf("%s ",p[a[j][0]].t);
    a[j][0]++;
   }
   printf(".\n");
   }
   return 0;
}
