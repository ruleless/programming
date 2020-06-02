#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

/*int partition(int*l,int low,int high)
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
}*/
int cmp ( const void *a , const void *b )
{
return *(int *)a - *(int *)b;
}



static int num[26]={
	2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9
};

int main()
{
	int tn,i,j,m,teln[100000];char c;
	//freopen("in.txt","r",stdin);
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
				teln[i]+=num[int(c-'A')]*m;m/=10;
			}			
			c=getchar();
		}
	}
	qsort(teln,tn,sizeof(int),cmp);
	bool noduplicate = true; 
    i=0; 
    while(i<tn)
	{
       j=i; 
       i++; 
       while(i<tn&&teln[i]==teln[j]) 
		   i++; 
       if(i-j>1)
	   { 
	    	cout<<setw(3)<<setfill('0')<<teln[j]/10000<<'-';
	    	cout<<setw(4)<<setfill('0')<<teln[j]%10000<<' '<<i-j<<endl;
            noduplicate = false; 
	   } 
	} 
    if(noduplicate) 
		printf("No duplicates.\n"); 
	return 0;
}
