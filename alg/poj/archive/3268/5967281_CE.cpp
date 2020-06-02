#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
#define INF 100000

int a[1010][1010];
int n,m,x;

void main(){
//	ifstream cin("data.txt");
//	cin>>n>>m>>x;
	scanf("%d%d%d",&n,&m,&x);
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)a[i][j]=0;
			else{
				a[i][j]=INF;
			}
		}
	}
	for(i=0;i<m;i++){
		int f,t,cost;
		//cin>>f>>t>>cost;
		scanf("%d%d%d",&f,&t,&cost);
		a[f][t]=cost;
	}
	for(k=1;k<=n;k++){   //floyd
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][k]+a[k][j]<a[i][j])a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	int max=-1;
	for(i=1;i<=n;i++){
		int tmp=a[i][x]+a[x][i];
		if(tmp>max)max=tmp;
	}
	cout<<max<<endl;

}
