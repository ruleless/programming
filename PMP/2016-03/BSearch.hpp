#include <stdio.h>

template <class T>
int bsearch(T *arr, int low, int high, T target)
{	
	while (low <= high)
	{
		int mid = (low+high) >> 1;
		if (target == arr[mid])
			return mid;
		else if (target > arr[mid])
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}
