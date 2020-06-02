#include <iostream>
#include <string>
using namespace std;

struct nums
{
    int num;
    char str[20];
};

nums nu[] = {
    {0,"zero"}, {1,"one"}, {2,"two"},
    {3,"three"}, {4,"four"}, {5,"five"},
    {6,"six"}, {7,"seven"}, {8,"eight"},
    {9,"nine"}, {10,"ten"}, {11,"eleven"},
    {12,"twelve"}, {13,"thirteen"}, {14,"fourteen"},
    {15,"fifteen"}, {16,"sixteen"}, {17,"seventeen"},
    {18,"eighteen"}, {19,"nineteen"}, {20,"twenty"},
    {30,"thirty"}, {40,"forty"}, {50,"fifty"},
    {60,"sixty"}, {70,"seventy"}, {80,"eighty"},
    {90,"ninety"},
    {-1,"negative"},
    {100,"hundred"},
    {1000,"thousand"},
    {1000000,"million"}
};

int main()
{
    char input[200];
    while(cin.getline(input,200))
    {
        string str = input;
		if(str!="")
		{
        int result = 0;
        int calc = 0;
        int mill = 0;
        int th = 0;
        bool b_na = false;
        bool b_hun = false;
        size_t pos=0,pos2=0;
        str += " ";
		int last=0;
        while((pos2=str.find(" ",pos))!=string::npos)
        {
            string calcstr = str.substr(pos,pos2-pos);
            pos = pos2+1;
            if(calcstr.compare(nu[28].str)==0)
            {
                b_na = true;
                continue;
            }
            
            for(int i=0;i<32;i++)
            {
                if(calcstr.compare(nu[i].str)==0)
                {
                    if(i==31)//million
                    {
						if(calc<1000000)
						{
							calc+=last;
							calc*=1000000;
						}
						else
						{
							last*=1000000;
							calc+=last;
						}
						last=0;
                        break;  
                    }
                    else if(i==29)//hundred
                    {
						if(calc<100)
						{
							calc+=last;
							calc*=100;
						}
						else
						{
							last*=100;
							calc+=last;
						}
						last=0;
						break;
                    }
                    else if(i==30)//thousand
                    {
						if(calc<1000)
						{
							calc+=last;
							calc*=1000;
						}
						else
						{
							int a=calc%1000;
							calc=calc-a;
							last=a+last;
							last*=1000;
							calc+=last;
						}
						last=0;
                        break;
                    }
                    else
					{
						//calc += nu[i].num;
						last+=nu[i].num;
						break;
					}
                }
            }
		
        }

        //result = mill+th+calc;
		if(last!=0)
				calc+=last;
        if(b_na)
            calc *= -1;
        cout<<calc<<endl;
		}
    }
	return 0;
}
