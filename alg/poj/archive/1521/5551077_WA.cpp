#include<iostream>
#include<cstring>
using namespace std;

int num[27],hlen[27];

struct node{
	char c;
	int weight,parent,lchild,rchild;
};

struct node HT[60];

void min(struct node*HT,int i,int&s1,int&s2)
{
	int k=0,j;
	while(HT[k].parent!=-1)k++;
	s1=k;
	for(j=k+1;j<i;j++)
		if(HT[j].weight<HT[s1].weight&&HT[j].parent==-1)
			s1=j;
	k=0;
	while(HT[k].parent!=-1||k==s1)k++;
	s2=k;
	for(j=k+1;j<i;j++)
		if(HT[j].weight<HT[s2].weight&&HT[j].parent==-1&&j!=s1)
			s2=j;
}

int main()
{
	//freopen("in.txt","r",stdin);
	char str[500];
	int i,j,cnt,s1,s2,sum,sum1,sum2;
	double res;
	gets(str);
	while(strcmp(str,"END")!=0)
	{
		for(i=0;i<=26;i++)
		{
			hlen[i]=0;
			num[i]=0;
		}
		for(i=0;i<strlen(str);i++)
			if(str[i]=='_')
				num[26]+=1;
			else
				num[str[i]-'A']+=1;

		for(i=0;i<60;i++)
		{
			HT[i].weight=0;
			HT[i].lchild=-1;
			HT[i].parent=-1;
			HT[i].rchild=-1;
		}

		cnt=0;
		for(i=0;i<27;i++)
			if(num[i]!=0)
			{
				HT[cnt].weight=num[i];
				if(i==26)
					HT[cnt].c='_';
				else
				    HT[cnt].c=char(i+'A');
				HT[cnt].parent=-1;
				HT[cnt].lchild=-1;
				HT[cnt].rchild=-1;
				cnt++;
			}
		if(cnt==1)
		{
			printf("%d %d %.1lf\n",HT[0].weight*8,HT[0].weight,1.0*8);
			break;
		}

		for(i=cnt;i<=2*cnt-2;i++)
		{
			min(HT,i,s1,s2);
			HT[s1].parent=i;
			HT[s2].parent=i;
			HT[i].lchild=s1;
			HT[i].rchild=s2;
			HT[i].weight=HT[s1].weight+HT[s2].weight;
		}
		for(i=0;i<cnt;i++)
		{
		//	printf("%d\n",HT[i].weight);
			sum=0;j=i;
			while(HT[j].parent!=-1)
			{
				sum+=1;
				j=HT[j].parent;
			}
			if(HT[i].c=='_')
				hlen[26]=sum;
			else
				hlen[HT[i].c-'A']=sum;
		}
		sum1=0;sum2=0;
		for(i=0;i<27;i++)
		{
			
		//	printf("%d %d\n",num[i],hlen[i]);
			sum1+=num[i]*8;
			sum2+=num[i]*hlen[i];
		}
		res=1.0*sum1/sum2;
		printf("%d %d %.1lf\n",sum1,sum2,res);


		gets(str);
	}
	return 0;
}