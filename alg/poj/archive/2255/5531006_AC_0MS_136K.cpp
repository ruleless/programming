#include<iostream>
using namespace std;

struct node{
	char c;
	node*left,*right;
};

char preord[27],inord[27];

void create(node*&p,int low,int high)
{
	p=new node;
	int i,j,flag=0;
	for(i=0;i<strlen(preord)&&flag==0;i++)
	{
		for(j=low;j<=high;j++)
			if(preord[i]==inord[j])
			{
				flag=1;break;
			}
		if(flag==1)
			break;
	}
	if(i==strlen(preord))
	{
		p=NULL;	return ;
	}
	else
	{
    	p->c=preord[i];p->left=NULL;p->right=NULL;
	}
	create(p->left,low,j-1);
	create(p->right,j+1,high);
}


void postord(node*p)
{
	if(p!=NULL)
	{
		postord(p->left);
		postord(p->right);
		printf("%c",p->c);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	node*p;
	while(scanf("%s",preord)!=EOF)
	{
		scanf("%s",inord);
		create(p,0,strlen(inord)-1);
		postord(p);
		putchar('\n');
	}
	return 0;
}
