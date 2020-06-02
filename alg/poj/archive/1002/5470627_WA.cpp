#include<iostream>
#include<cstring>
using namespace std;

int partition(char**l,int low,int high)
{
	char temp[9];
	strcpy(temp,l[low]);
	while(low<high)
	{
		while(low<high&&!(strcmp(l[high],temp)==-1))
			--high;
		strcpy(l[low],l[high]);
		while(low<high&&!(strcmp(l[low],temp)==1))
			++low;
		strcpy(l[high],l[low]);
	}
	strcpy(l[low],temp);
	return low;
}
	
void qsort(char**l,int low,int high)
{
	int pivotpos;
	if(low<high)
	{
		pivotpos=partition(l,low,high);
		qsort(l,low,pivotpos-1);
		qsort(l,pivotpos+1,high);
	}
}

void quicksort(char**tel,int tn)
{
	qsort(tel,0,tn-1);
}



int main()
{
	int tn,i,j,k;char **tel,c;
	//freopen("in.txt","r",stdin);
	scanf("%d",&tn);getchar();
	tel=new char*[tn];
	for(i=0;i<tn;i++)
	{
		tel[i]=new char[9];k=0;
		c=getchar();
		while(c!=13&&c!=10&&c!=EOF)
		{
			if(c>='0'&&c<='9')
			{
				tel[i][k]=c;k++;
			}
			else if(c=='-');
			else
			{
				switch(c)
				{
				case 'A':
					 tel[i][k]='2';k++;break;
				case 'B':
					 tel[i][k]='2';k++;break;
				case 'C':
					 tel[i][k]='2';k++;break;
				case 'D':
					tel[i][k]='3';k++;break;
				case 'E':
					tel[i][k]='3';k++;break;
				case 'F':
					tel[i][k]='3';k++;break;
				case 'G':
				    tel[i][k]='4';k++;break;
				case 'H':
				    tel[i][k]='4';k++;break;
				case 'I':
				    tel[i][k]='4';k++;break;
				case 'J':
					 tel[i][k]='5';k++;break;
				case 'K':
					 tel[i][k]='5';k++;break;
				case 'L':
					 tel[i][k]='5';k++;break;
				case 'M':
					 tel[i][k]='6';k++;break;
				case 'N':
					 tel[i][k]='6';k++;break;
				case 'O':
					 tel[i][k]='6';k++;break;
				case 'P':
					 tel[i][k]='7';k++;break;
				case 'R':
					 tel[i][k]='7';k++;break;
				case 'S':
					 tel[i][k]='7';k++;break;
				case 'T':
					 tel[i][k]='8';k++;break;
				case 'U':
					 tel[i][k]='8';k++;break;
				case 'V':
					 tel[i][k]='8';k++;break;
				case 'W':
					 tel[i][k]='9';k++;break;
				case 'X':
					 tel[i][k]='9';k++;break;
				case 'Y':
					 tel[i][k]='9';k++;break;
				}				
			}
			c=getchar();
		}
		tel[i][k]='\0';
	}
	/*for(i=0;i<tn;i++)
		for(j=i+1;j<tn;j++)
			if(strcmp(tel[j],tel[i])==-1)
			{
				strcpy(temp,tel[i]);
				strcpy(tel[i],tel[j]);
				strcpy(tel[j],temp);
			}*/
	quicksort(tel,tn);
	//for(i=0;i<tn;i++)
		//printf("%s\n",tel[i]);
	i=0;j=1;
	while(i<=tn-2)
	{
		if(j<=tn-1&&strcmp(tel[i],tel[j])==0)
			j++;
		else
		{
			if(j-i>=2)
			{
				for(k=0;k<3;k++)
					putchar(tel[i][k]);
				putchar('-');
				for(k=3;k<=6;k++)
					putchar(tel[i][k]);
				printf(" %d\n",j-i);
				i=j;j++;
			}
			else
			{
				i=j;j++;
			}
		}
	}
	return 0;

}
