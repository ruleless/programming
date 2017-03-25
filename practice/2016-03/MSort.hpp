#include <stdio.h>

template <class T>
void mSort(T *arr, int low, int high)
{
	if (low >= high)
		return;

	int mid = (low+high) >> 1;
	mSort(arr, low, mid);
	mSort(arr, mid+1, high);

	T *tempArr = new T[high-low+1];
	int i = low, j = mid+1, k=0;
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[k++] = arr[i++];
		}
		else
		{
			tempArr[k++] = arr[j++];
		}
	}
	while (i <= mid)
	{
		tempArr[k++] = arr[i++];
	}
	while (j <= high)
	{
		tempArr[k++] = arr[j++];
	}

	for (i = low; i <= high; ++i)
	{
		arr[i] = tempArr[i-low];
	}
	delete []tempArr;
}
