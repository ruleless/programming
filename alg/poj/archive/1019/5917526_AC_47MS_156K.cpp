#include <stdio.h>

int inc(__int64 k)
{
	int len = 0;
	while(k != 0)
	{
		len++;
		k = k / 10;
	}
	return len;
}

int main()
{
	__int64 i,j,n,k,len;

	scanf("%I64d",&n);
	while (n--)
	{
		scanf("%I64d",&i);
		j = len = 0;
		k = 1;
		while (j < i)				{
			len += inc(k);
			k++;
			j += len;
		}
		
		j -= len;
		k = 1;
		while (j < i)          		{
			j += inc(k);
			k++;
		}
		k--;
		j -= inc(k);
		len = inc(k) - (i - j);
		while(len--)          
			k = k / 10;

		printf("%I64d\n",k % 10);
	}

	return 0;
}
