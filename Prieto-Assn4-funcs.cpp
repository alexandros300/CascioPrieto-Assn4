#include "Prieto-assn4-funcs.h"
#include "PrietoCascio-assn4-common.h"
#include <ctime>
#include <string>
using namespace std;

/*******************************************************************************
FUNCTION: partition
DESCRIPTION: pick one element in the array to serve as a "pivot" point. Then 
re-arranges the elements to partition the array. The left side of the array 
will contain all elements smaller than the pivot point, and the right side will 
contain all elements larger than the pivot point.
INPUT: 
Parameters: *sortArray, int p, int q. 
CALLS TO: swap
IMPLEMENTED BY: Prieto
*******************************************************************************/
int partition(int *sortArray, int p, int q);
{
	int x = sortArray[p];
	int i = p;
	int j;

	for (j = p + 1; j<q; j++)
	{
		if (sortArray[j] <= x)
		{
			i = i + 1;
			swap(&sortArray[i], &sortArray[j]);
		}
	}
	swap(&sortArray[i], &sortArray[p]);
	return i;
}

/*******************************************************************************
FUNCTION: mergesort
DESCRIPTION: The array is split into two halves andd are first copied into a 
temporary array. Then the two halves are scanned using two indexes and the 
respective next-greatest element at each time is copied back to the original array.
INPUT: 
Parameters: *sortArray, *templist, int low, int high 
CALLS TO: merge
IMPLEMENTED BY: Prieto
*******************************************************************************/
void mergesort(int *sortArray, int *tempList, int low, int high);
{
	int pivot;
	if (low<high)
	{
		pivot = (low + high) / 2;
		mergesort(arraySort, tempList, low, pivot);
		mergesort(arraySort, tempList, pivot + 1, high);
		merge(arraySort, tempList, low, pivot, high);
	}
}

/*******************************************************************************
FUNCTION: insertionSort
DESCRIPTION: This function utilizes the in-place sort. Works by moving each item 
into the correct place repeatedly swapping it with larger items in the sorted 
portion of the list.
INPUT: 
Parameters: *sortArray, int size
CALLS TO: swap
IMPLEMENTED BY: Prieto
*******************************************************************************/
void insertionSort(int *sortArray, int size);
{
	int selectedElement = 0;
	int j = 0;
	for (int i = 0; i <= size - 1; i++) {
		selectedElement = sortArray[i];
		j = i;
		while (j > 0 && sortArray[j] < sortArray[j - 1]) {
			swap(&sortArray[j], &sortArray[j - 1]);
			j--;
		}
	}
}
