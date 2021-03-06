#include<iostream>
#include<cstring>
using namespace std;

short int partition(char**l,short int low,short int high)
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

void qsort(char**l,short int low,short int high)
{
	short int pivotpos;
	if(low<high)
	{
		pivotpos=partition(l,low,high);
		qsort(l,low,pivotpos-1);
		qsort(l,pivotpos+1,high);
	}
}

void quicksort(char**tel,short int tn)
{
	qsort(tel,0,tn-1);
}



short int main()
{
	short int tn,i,j,k,flag=0;char **tel,c;
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
	quicksort(tel,tn);
	bool noduplicate = true; 
   i=0; 
   while(i<tn){//搜索重复的电话号码，并进行输出 
    j=i; 
    i++; 
    while(i<tn&&strcmp(tel[i], tel[j])==0) i++; 
    if(i-j>1) { 
     printf("%.3s-", tel[j]);
	 for(k=3;k<7;k++)
		 putchar(tel[j][k]);
	 printf(" %d\n",i-j);
     noduplicate = false; 
    } 
   } 
    if ( noduplicate ) 
    printf("No duplicates.\n"); 
	return 0;
}
