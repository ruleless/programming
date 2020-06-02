#include<iostream>
using namespace std;
int main()
{
    int cyle,a,b;
    cin>>cyle;
    while(cyle--) {
        cin>>a>>b;
        if(a<b||(a+b)%2||(a-b)%2)cout<<"impossible"<<endl;
        else
        {
            cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
        }
    }
    return 0;
}

