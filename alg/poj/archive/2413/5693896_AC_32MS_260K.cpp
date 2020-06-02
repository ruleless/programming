#include<iostream>
#include<cstring>
using namespace std;

void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;up=0;
    while(i>=0||j>=0)
        {
            if(i<0) x='0'; else x=a[i];
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';
            if(up) z+=1;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
            i--;j--;
        }
    if(up) c[k++]='1';
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
} 

struct node{
	char str[110];
	int index;
};

struct node result[520];

int strcmp1(char*a,char*b)
{
	if(strlen(a)>strlen(b))
		return 1;
	else if(strlen(a)<strlen(b))
		return -1;
	else
		return strcmp(a,b);
}



int main()
{
//	freopen("in.txt","r",stdin);
	int i=1,j,sum;
	char a[110],b[110];
	result[0].index=1;
	strcpy(result[0].str,"1");
	result[1].index=2;
	strcpy(result[1].str,"2");
	while(strlen(result[i].str)<=100)
	{
		i++;
		add(result[i-2].str,result[i-1].str,result[i].str);
		result[i].index=i+1;
	}
	while(scanf("%s%s",a,b),!(strcmp(a,"0")==0&&strcmp(b,"0")==0))
	{
		sum=0;
		for(j=0;j<=i&&strcmp1(result[j].str,b)!=1;j++)
			if(strcmp1(result[j].str,a)!=-1)
			{
				sum++;
			}
		printf("%d\n",sum);
	}

	return 0;
}