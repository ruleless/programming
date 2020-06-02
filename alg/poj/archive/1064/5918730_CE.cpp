#include <iostream>
#include <algorithm>
using namespace std;
double t;
__int64 num[100000],start,mid,end;__int64 sum,n,k;
int main(){
	__int64 i;
	scanf("%I64d%I64d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%lf",&t);
			t*=100;
			num[i]=int(t);
			sum+=num[i];
		}
		if(sum<k){printf("0.00\n");continue;}
		sort(num,num+n);
		start=1;end=num[0];
		while(start+1<end){
			sum=0;
			mid=(start+end)/2;
			for(i=0;i<n;i++)sum+=num[i]/mid;
			if(sum<k)end=mid;
			if(sum>=k)start=mid;
		}
		sum=0;
		for(i=0;i<n;i++)sum+=num[i]/end;
		if(sum>=k)printf("%.2lf\n",end*0.01);			
		else printf("%.2lf\n",start*0.01);
	
	return 0;
}
