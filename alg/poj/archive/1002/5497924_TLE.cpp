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
	int tn,i,j,m,teln[100000];char c;
//	freopen("in.txt","r",stdin);
	scanf("%d",&tn);getchar();
	for(i=0;i<tn;i++)
	{
	
		c=getchar();m=1000000;teln[i]=0;
		while(c!=13&&c!=10&&c!=EOF)
		{
			if(c>='0'&&c<='9')
			{
				teln[i]+=int(c-48)*m;m/=10;
			}
			else if(c=='-');
			else
			{
				switch(c)
				{
				case 'A':
					 teln[i]+=2*m;m/=10;break;
				case 'B':
					 teln[i]+=2*m;m/=10;break;
				case 'C':
					 teln[i]+=2*m;m/=10;break;
				case 'D':
					teln[i]+=3*m;m/=10;break;
				case 'E':
					teln[i]+=3*m;m/=10;break;
				case 'F':
					teln[i]+=3*m;m/=10;break;
				case 'G':
				    teln[i]+=4*m;m/=10;break;
				case 'H':
				    teln[i]+=4*m;m/=10;break;
				case 'I':
				    teln[i]+=4*m;m/=10;break;
				case 'J':
					 teln[i]+=5*m;m/=10;break;
				case 'K':
					 teln[i]+=5*m;m/=10;break;
				case 'L':
					 teln[i]+=5*m;m/=10;break;
				case 'M':
					 teln[i]+=6*m;m/=10;break;
				case 'N':
					 teln[i]+=6*m;m/=10;break;
				case 'O':
					 teln[i]+=6*m;m/=10;break;
				case 'P':
					 teln[i]+=7*m;m/=10;break;
				case 'R':
					 teln[i]+=7*m;m/=10;break;
				case 'S':
					 teln[i]+=7*m;m/=10;break;
				case 'T':
					 teln[i]+=8*m;m/=10;break;
				case 'U':
					 teln[i]+=8*m;m/=10;break;
				case 'V':
					 teln[i]+=8*m;m/=10;break;
				case 'W':
					 teln[i]+=9*m;m/=10;break;
				case 'X':
					 teln[i]+=9*m;m/=10;break;
				case 'Y':
					 teln[i]+=9*m;m/=10;break;
				}				
			}
			c=getchar();
		}
	}
	quicksort(teln,tn);
	bool noduplicate = true; 
   i=0; 
   while(i<tn){
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
