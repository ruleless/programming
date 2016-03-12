#include <stdio.h>

template <class T>
int locationPivot(T *arr, int low, int high)
{
	int pivot = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= pivot) --high;
		if (low < high)
			arr[low] = arr[high];
		else
			break;		

		while (low < high && arr[low] <= pivot) ++low;
		if (low < high)
			arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

template <class T>
void qSort(T *arr, int low, int high)
{
	if (low >= high)
		return;
	int pivotPos = locationPivot(arr, low, high);
	qSort(arr, low, pivotPos-1);
	qSort(arr, pivotPos+1, high);
}
