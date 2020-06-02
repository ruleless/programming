#include<iostream.h>
#include<string.h>

int main()
{
	int million,thousand,i,j,m,pos,p,num=0,tt[100];char snum[15],str[101];
	cin.getline(str,100);
	for(j=strlen(str);j<101;j++)
		str[j]='\0';
	while(str[0]!='\0')
	{
		m=0;million=0;thousand=0;pos=1;p=0;
		while(str[p]!='\0')
		{
			i=0;
			while(str[p]!='\0'&&str[p]!=' ')
			{
				snum[i]=str[p];
				i++;p++;
			}
			snum[i]='\0';
			p++;
			if(strcmp(snum,"negative")==0)
				pos=-1;
			else if(strcmp(snum,"one")==0)
				m+=1;
			else if(strcmp(snum,"two")==0)
				m+=2;
			else if(strcmp(snum,"three")==0)
				m+=3;
			else if(strcmp(snum,"four")==0)
				m+=4;
			else if(strcmp(snum,"five")==0)
				m+=5;
			else if(strcmp(snum,"six")==0)
				m+=6;
			else if(strcmp(snum,"seven")==0)
				m+=7;
			else if(strcmp(snum,"eight")==0)
				m+=8;
			else if(strcmp(snum,"nine")==0)
				m+=9;
			else if(strcmp(snum,"ten")==0)
				m+=10;
			else if(strcmp(snum,"eleven")==0)
				m+=11;
			else if(strcmp(snum,"twelve")==0)
				m+=12;
			else if(strcmp(snum,"thirteen")==0)
				m+=13;
			else if(strcmp(snum,"fourteen")==0)
				m+=14;
			else if(strcmp(snum,"fifteen")==0)
				m+=15;
			else if(strcmp(snum,"sixteen")==0)
				m+=16;
			else if(strcmp(snum,"seventeen")==0)
				m+=17;
			else if(strcmp(snum,"eighteen")==0)
				m+=18;
			else if(strcmp(snum,"nineteen")==0)
				m+=19;
			else if(strcmp(snum,"twenty")==0)
				m+=20;
			else if(strcmp(snum,"thirty")==0)
				m+=30;
			else if(strcmp(snum,"forty")==0)
				m+=40;
			else if(strcmp(snum,"fifty")==0)
				m+=50;
			else if(strcmp(snum,"sixty")==0)
				m+=60;
			else if(strcmp(snum,"seventy")==0)
				m+=70;
			else if(strcmp(snum,"eighty")==0)
				m+=80;
			else if(strcmp(snum,"ninety")==0)
				m+=90;
			else if(strcmp(snum,"hundred")==0)
				m*=100;
			else if(strcmp(snum,"thousand")==0)
			{
				m*=1000;
				thousand=m;
				m=0;
			}
			else if(strcmp(snum,"million")==0)
			{
				m*=1000000;
				million=m;
				m=0;
			}
		}
		tt[num]=pos*(m+million+thousand);
		num++;
		cin.getline(str,100);
		for(j=strlen(str);j<101;j++)
		     str[j]='\0';
	}
	for(i=0;i<num;i++)
		cout<<tt[i]<<endl;
	return 0;
}

