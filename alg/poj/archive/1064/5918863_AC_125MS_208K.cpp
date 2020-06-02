#include <iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
int n,k,i,big,be,en,mid,num; double ans,a;
int l[10001];
scanf("%d%d",&n,&k);
big=0;
for(i=0;i<n;i++)
{
scanf("%lf",&a);
l[i]=int(a*100.0);
if(l[i]>big) big=l[i];
}

be=0;en=big;
while(be<en)
{

mid=(be+en)/2+1;
// printf("%d\n",mid);
num=0;
for(i=0;i<n;i++)
{
num+=l[i]/mid;
if(num>=k) break;
}
if(num>=k) be=mid; 
else en=mid-1;

}
ans=double(be/100.0);
printf("%.2lf\n",ans);


return 0;
}
