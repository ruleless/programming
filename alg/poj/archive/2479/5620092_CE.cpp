#include<iostream>
using namespace std;
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
                                    //初始化
        
       int  max=a[0]+a[1];         // 通过逐一扫描最后一个选中的元素位置，得解
       int  temp1=a[0];            //0到i-2内单个最大子段
       int temp3=a[0];             // 0到i-2内以i-2为最后选中位置的单个最大子段
       int  temp2=a[0]+a[1];       //以i为最后选中元素时题目要求的两段最大值
       
        
       for(int i=2;i<n;i++)
       {    
            temp2=(temp2>temp1?temp2:temp1)+a[i];  //两种情况。是否包含i-1
              
            if(temp2>max)max=temp2;
            temp3=(temp3>0?temp3:0)+a[i-1];      //更新
            temp1=temp1>temp3?temp1:temp3;       //是否包含i-1 
      }
           
      cout<<max<<endl;      
             
   }            
                
     return 0;          
                
                
  }
