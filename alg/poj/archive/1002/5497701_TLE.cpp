#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int partition(int*l,int low,int high)
{
	int temp;
	temp=l[low];
	while(low<high)
	{
		while(low<high&&l[high]>=temp)
			--high;
		l[low]=l[high];
		while(low<high&&l[low]<=temp)
			++low;
		l[high]=l[low];
	}
	l[low]=temp;
	return low;
}

void qsort(int*l,int low,int high)
{
	int pivotpos;
	if(low<high)
	{
		pivotpos=partition(l,low,high);
		qsort(l,low,pivotpos-1);
		qsort(l,pivotpos+1,high);
	}
}

void quicksort(int*tel,int tn)
{
	qsort(tel,0,tn-1);
}



int main()
{
	int tn,i,j,k,flag=0,m,*teln;char **tel,c;
	//freopen("in.txt","r",stdin);
	scanf("%d",&tn);getchar();
	tel=new char*[tn];teln=new int[tn];
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
		
		tel[i][k]='\0';teln[i]=0;m=1;
	//	printf("%s\n",tel[i]);
	
		for(j=6;j>=0;j--)
		{
			teln[i]+=int(tel[i][j]-48)*m;m*=10;//printf("%d",tel[i][6-j]-48);
		}
	//	printf("%d\n",teln[i]);
			//putchar('\n');

	}//putchar('\n');
	quicksort(teln,tn);
	bool noduplicate = true; 
   i=0; 
   while(i<tn){//搜索重复的电话号码，并进行输出 
    j=i; 
    i++; 
    while(i<tn&&teln[i]==teln[j]) i++; 
    if(i-j>1) { 
		cout<<setw(3)<<setfill('0')<<teln[j]/10000<<'-';
		cout<<setw(4)<<setfill('0')<<teln[j]%10000<<' '<<i-j<<endl;
		//printf("%d-",teln[j]/10000);
	//	printf("%d %d\n",teln[j]%10000,i-j);
     noduplicate = false; 
    } 
   } 
    if ( noduplicate ) 
    printf("No duplicates.\n"); 
	return 0;
}
