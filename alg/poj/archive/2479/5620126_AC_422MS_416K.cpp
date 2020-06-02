#include<iostream>
using namespace std;
int a[50005];
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
                                           
       int  max=a[0]+a[1];        
       int  temp1=a[0];            
       int temp3=a[0];             
       int  temp2=a[0]+a[1];              
        
       for(int i=2;i<n;i++)
       {    
            temp2=(temp2>temp1?temp2:temp1)+a[i];                
            if(temp2>max)max=temp2;
            temp3=(temp3>0?temp3:0)+a[i-1];      
            temp1=temp1>temp3?temp1:temp3; 
       }      
           
      cout<<max<<endl;      
             
   }            
                
     return 0;          
                             
  }
