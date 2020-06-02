#include<stdio.h>
#include<string.h>
int i,j,n,m;

bool p[1000],check[1000];
char s[500];


void main(){
	while(scanf("%d",&n),n){
		memset(p,0,sizeof(p));
		memset(check,0,sizeof(check));
		scanf(" %s ",s);
		m=0;
		for (i=0;i<strlen(s);i++){
			if (p[s[i]]){p[s[i]]=0;if (!check[s[i]])n++;else m++;}
			else 
			{p[s[i]]=1;if (n) n--;else check[s[i]]=1;};
		};
		if (m) printf("%d customer(s) walked away.\n",m);
		else printf("All customers tanned successfully.\n");
	};
	return;
};
