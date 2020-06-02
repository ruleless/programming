#include<iostream>
using namespace std;

const int maxn=100;

int n,m,s;
double v,d[maxn];

double exc[maxn][maxn];

struct Edge {
	int u,
		v;
}edge[maxn];

void iss() {	//initialize_single_source
	for(int i=0;i<n;i++) {
		d[i]=0;
	}
	d[s]=1;
}

void relax(int u,int v) {
	if(d[v]<d[u]*exc[u][v]) {
		d[v]=d[u]*exc[u][v];
	}
}

bool bf() {	//bellman_ford
	int i,j;
	iss();

	for(i=0;i<n-1;i++) {
		for(j=0;j<m;j++) {
			relax(edge[j].u,edge[j].v);
			relax(edge[j].v,edge[j].u);
		}
	}

	for(i=0;i<m;i++) {
		int u=edge[i].u, v=edge[i].v;
		if(d[v]<d[u]*exc[u][v] || d[u]<d[v]*exc[v][u]) return false;
	}

	return true;
}

int main() {
//	freopen("in.txt","r",stdin);
	cin>>n>>m>>s>>v;
	s--;	//start from 0
	for(int i=0;i<m;i++) {
		int a,b;
		double r1,c1,r2,c2;
		cin>>a>>b>>r1>>c1>>r2>>c2;
		a--; b--;
		exc[a][b]=(1-c1/100)*r1;
		exc[b][a]=(1-c2/100)*r2;
		edge[i].u=a;
		edge[i].v=b;
	}
	if(v!=0&&!bf()) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}

