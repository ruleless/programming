#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10000
#define _match(a,b)((a)==(b))

int pat_match(int ls,char* str,int lp,char*pat)
{
    int fail[MAXN]={-1},i=0,j;
    for(j=1;j<lp;j++)
    {
        for(i=fail[j-1];i>=0&&!_match(pat[i+1],pat[j]);i=fail[i]);
        fail[j]=(_match(pat[i+1],pat[j])?i+1:-1);
    }
    for(i=j=0;i<ls&&j<lp;i++)
    {
        if(_match(str[i],pat[j]))
            j++;
        else if(j)
            j=fail[j-1]+1,i--;
    }
    return j==lp?(i-lp):-1;
}

int SafeStrcpy2KeyWord(char* pDestBuffer,	//源字符串
		       char* pSourceString,	//目的字符串
		       int nDestBufferSize,	//缓冲区长度
		       char* szKeyWord)	//指定键字符串
{
    int m=strlen(pDestBuffer);
    int n=strlen(szKeyWord);
    int k=pat_match(m,pDestBuffer,n,szKeyWord);
    if(k==-1)
    {
        strcpy(pSourceString,pDestBuffer);
        return strlen(pDestBuffer);;
    }
    int i;
    for(i=0;i<k;i++)
        pSourceString[i]=pDestBuffer[i];
    pSourceString[i]='\0';
    return strlen(pSourceString);
}

int main(int argc, char *argv[])
{
  char s[260],d[260],key[30];
  //printf("%d\n",pat_match(strlen("/home/tony/work_server/1/rtest/relayer.out"),"/home/tony/work_server/1/rtest/relayer.out",strlen("/1/r"),"/1/r"));
  //freopen("in.txt","r",stdin);
  int flag;
  int n;
    while(scanf("%s",s)!=-1)
    {
         while(scanf("%s",key),strcmp(key,"END"))
         {
                flag=1;
                if(strcmp(key,"NULL")==0)
                {
                    printf("0 NULL\n");
                    flag=0;
                }
                if(flag)
                {
                    n=SafeStrcpy2KeyWord(s,d,0,key);
                    if(n==0)
                        printf("%d NULL\n",n);
                    else 
                       printf("%d %s\n",n,d);
                }              
         }
    }
  //system("PAUSE");	
  //while(1);
  return 0;
}
