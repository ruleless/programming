/*
任意进制转换 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[555],d[555];
void change(int a,int b)
{
    int i,l,k,t[555],A[555];
    for(k=i=strlen(s);0<i--;)t[k-1-i]=s[i]-(s[i]<58?48:s[i]<97?55:61);
    for(l=0;k;)
    {
		for(i=k;1<i--;)
        {
			t[i-1]+=t[i]%b*a;
			t[i]/=b;
		}
		A[l++]=t[0]%b;
		t[0]/=b;
		for(;0<k&&!t[k-1];k--);
	}
	for(d[l]=i=0;i<l;i++)d[l-1-i]=A[i]+(A[i]<10?48:A[i]<36?55:61);
}
int main()
{
} 
