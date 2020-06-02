#include <iostream>
#include <queue>
using namespace std;
bool matL[510][510];
bool matR[510][510];
bool Rvisited[510];
bool Lvisited[510];
int N,K;
struct nod
{
	int drect;//0:L,1:R
	int seq;
};
nod L[510];
nod R[510];
int Lp[510];
int Rp[510];

int cnt;

void inpt()
{
	int l,r;
	int i;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;++i)
	{
		matR[i][N+1]=1;//N+1列保存R到终点的情况
	}
	while(K--)
	{
		scanf("%d%d",&l,&r);
		matL[l][r]=1;
	}
	for(i=1;i<=N;++i)
	{
		L[i].drect=0;
		R[i].drect=1;
		L[i].seq=i;
		R[i].seq=i;
	}
}

void solve()
{
	int i,j;
	queue<nod> temp;
	nod p;
	int t;
	int x;
	int ex;
	for(i=1;i<=N;++i)
	{
		memset(Rvisited,0,sizeof(Rvisited));
		memset(Lvisited,0,sizeof(Lvisited));
		while(!temp.empty())
			 temp.pop();
		temp.push(L[i]);
		ex=0;
		while(!temp.empty()&&(!ex))
		{
			p=temp.front();
			temp.pop();
			if(p.drect==0)
			{
				for(j=1;j<=N;++j)
				{
					if(matL[p.seq][j]&&(!Rvisited[j]))
					{
						temp.push(R[j]);
						Rp[j]=p.seq;
						Rvisited[j]=1;
					}
				}
			}
			else
			{
				for(j=1;j<=N+1;++j)
				{
					if(matR[p.seq][j]&&(!Lvisited[j]))
					{
						if(j==N+1)
						{
							matR[p.seq][N+1]=0;
							t=Rp[p.seq];
							x=p.seq;
							while(t!=i)
							{
								matL[t][x]=0;
								matR[x][t]=1;
								x=t;
								t=Lp[x];
								matR[t][x]=0;
								matL[x][t]=1;
								x=t;
								t=Rp[x];
							}
							matL[t][x]=0;
							matR[x][t]=1;
							cnt++;
							ex=1;
							break;
						}
						else
						{
							temp.push(L[j]);
							Lp[j]=p.seq;
							Lvisited[j]=1;
						}
					}
				}
			}
		}
	}
}
void outp()
{
	printf("%d\n",cnt);
}
int main()
{
	inpt();
	solve();
	outp();
	return 0;
}