#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char s[10],e[10],m[210];
    int i,n;
   // freopen("in.txt","r",stdin);
    while(1)
    {
        gets(s);
        if(strcmp(s,"ENDOFINPUT")==0)
        {
            break;
        }
        gets(m);
        n=strlen(m);
        for(i=0;i<n;i++)
        {
            if(m[i]>='A'&&m[i]<='Z')
            {
                m[i]=(char)(((int)((m[i]-'A'))+21)%26+'A');
            }
        }
        puts(m);
        gets(e);
        
    }
  
 // system("PAUSE");	
  //while(1);
  return 0;
}
