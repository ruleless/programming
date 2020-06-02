#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

typedef struct sea
{
 int x;
 int y;
} Sea;
typedef struct Radar
{
 double Rm;
 double Lm;
} Rader;

int comp(const void *p1, const void *p2) 
{ 
   Radar I1 = *(Radar *)p1; 
   Radar I2 = *(Radar *)p2; 
   double temp = I1.Rm - I2.Rm; 
   if (temp > 0.0) return 1; 
   else if (temp < 0.0) return -1; 
}


int main()
{
 int n,d;
 int count=1;
 while(cin>>n>>d&&n!=0&&d!=0)
 {
  bool index=false;
  int ans=1;
  Sea *island=new Sea[n+1];
  Rader *radar=new Rader[n+1];
  for(int i=0;i<n;i++)//inital
  {
   cin >>island[i].x >>island[i].y;
  }
  if(d<0)
  {
                cout<<"Case "<<count<<": "<<"-1"<<endl;
    delete [] island;
    delete [] radar;
    index=true;
    count++;
       index=true;
  }
  if(index)
   continue;
  for(int i=0;i<n;i++)
  {
   double temp;
   if((d*d-(island[i].y*island[i].y))>=0)
   temp=sqrt(double(d*d-(island[i].y*island[i].y)));
   else
   {
    cout<<"Case "<<count<<": "<<"-1"<<endl;
    delete [] island;
    delete [] radar;
    index=true;
    count++;
    break;
    
   }
   radar[i].Rm=island[i].x+temp;
   radar[i].Lm=island[i].x-temp;

  }

  if(index)
   continue;

  qsort(radar,n,sizeof(radar[0]),comp);//排序

  double ml,mr;
  ml=radar[0].Lm;
  mr=radar[0].Rm;
  for(int  i=1;i<n;i++)
  {
   if(radar[i].Lm<=mr)
   {
    if(ml<radar[i].Lm)
     ml=radar[i].Lm;
    if(radar[i].Rm<mr)
     mr=radar[i].Rm;
   }
   else
   {
    ml=radar[i].Lm;
    mr=radar[i].Rm;
                ans++;
   }
  }
  cout<<"Case "<<count<<": "<<ans<<endl;
  delete [] island;
  delete [] radar;
  count++;
  scanf("\n");
 }
 return 0;
}
