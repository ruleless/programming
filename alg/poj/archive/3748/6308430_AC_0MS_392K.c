#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    unsigned int r,x,y;
    scanf("%x,%u,%u",&r,&x,&y);
    r&=(0xffffffff-(int)(pow(2,x)));
    r|=(unsigned int)(pow(2,y)+pow(2,y-1));
    r&=(0xffffffff-(unsigned int) (pow(2,y-2)));
    printf("%x\n",r);
    //system("PAUSE");
    //while(1);
    return 0;
}
