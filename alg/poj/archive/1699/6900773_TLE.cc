#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;
char str[15][22];
string s;
int next[22],res;

int check(string ss,char* p,int i)
{
    int k=strlen(p);
    if(i+1>ss.length())
    {
        return 0;
    }
    int j=ss.length()-1;
    for(;i>=0;i--)
    {
        if(p[i]!=ss.at(j))
        {
            return 0;
        }
        j--;
    }
    return 1;
}

void solve()
{
    int i,j,l;
    for(i=0;i<n;i++)
    {
        next[i]=i;
    }
    do
    {
        int temp=0;
        for(i=0;i<n;i++)
        {
            for(j=strlen(str[next[i]])-1;j>=0&&check(s,str[next[i]],j)==0;j--);
            char tt[22];
            int len=strlen(str[next[i]]),ii=0;
            for(l=j+1;l<len;l++)
            {
                tt[ii++]=str[next[i]][l];
            }
            tt[ii]='\0';
            s=s+string(tt);
        }
        temp=s.length();
        if(temp<res)
        {
            res=temp;
        }
        s=string("");
    }while(next_permutation(next,next+n));
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res=1<<30;
        for(i=0;i<n;i++)
        {
            cin>>str[i];
        }
        solve();
        cout<<res<<'\n';
    }
   // while(1);
  
  //system("PAUSE");	
  return 0;
}
