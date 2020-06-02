#include<iostream>
#include<queue>
using namespace std;

int n,m[110][110];

void ek(int s,int e) {
	int q[2100],head,tail,i,j,pre[110],flow = 0;
	bool v[110];
	while(true) {
		memset(v,0,sizeof(v));
		head = tail = 0;
		q[++ tail] = s;
		v[s] = true;
		while(head != tail) {
			i = q[++ head];
			for(j = 0; j< n;j ++) {
				if(!v[j] && m[i][j] > 0) {
					pre[j] = i;
					if(j == e) break;
					q[++ tail] = j;
					v[j] = true;
				}
			}
			if(j == e) break;
		}
		if(j != e) break;
		int c= 1<<30;
		j = e;
		while(j != s) {
			i = pre[j];
			if(c > m[i][j]) {
				c = m[i][j];
			}
			j  = i;
		}
		flow += c;
		j = e;
		while(j != s) {
			i = pre[j];
			m[i][j] -= c;
			m[j][i] += c;
			j = i;
		}
	}
	printf("%d\n",flow);
}

void pp(int s,int e) {
	int f[110],h[110];
	memset(h,0,sizeof(h));
	memset(f,0,sizeof(f));
	queue<int> q;
	f[s] = 1<<30;
	h[s] = n;
	h[e] = 0;
	q.push(s);
	int i,j,mmin,flow = 0;
	while(!q.empty()) {
		i = q.front();
		q.pop();
		for(j = 0;j < n;j ++) {
			mmin = m[i][j] < f[i] ? m[i][j] : f[i];
			if(mmin && (h[i] == h[j] + 1 || i == s)) {
				f[i] -= mmin;
				f[j] += mmin;
				m[i][j] -= mmin;
				m[j][i] += mmin;
				if(j == e) {
					flow += mmin;
				}
				else if(j != s) {
					q.push(j);
				}
			}
		}
		if(f[i] && i != s) {
			h[i] ++;
			q.push(i);
		}
	}
	printf("%d\n",flow);
}

int main() {
//	freopen("in.txt","r",stdin);
	int np,nc,ne,i,j,b,e,w;
	char s[20];
	while(scanf("%d%d%d%d",&n,&np,&nc,&ne) != EOF) {
		memset(m,0,sizeof(m));
		for(i = 1;i <= ne;i ++) {
			scanf("%s",s);
			sscanf(s,"(%d,%d)%d",&b,&e,&w);
			m[b][e] = w;
		}
		for(i = 1;i <= np;i ++) {
			scanf("%s",s);
			sscanf(s,"(%d)%d",&e,&w);
			m[n][e] = w;
		}
		++ n;
		for(i = 1;i <= nc;i ++) {
			scanf("%s",s);
			sscanf(s,"(%d)%d",&b,&w);
			m[b][n] = w;
		}
		++ n;
//		ek(n - 2,n - 1);
		pp(n - 2,n - 1);
	}
	return 0;
}
