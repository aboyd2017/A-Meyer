#include "search.hpp"

int binarySearch(int list[], int to_find, int start_index, int end_index)
{
	int mid = (start_index + end_index) / 2;

	// Check indeces
	if (start_index > end_index)
		return -1;

	if (to_find == list[mid])
	{
		return mid;
	}
	else if (to_find < list[mid])
	{
		return binarySearch (list, to_find, start_index, mid-1);
	}
	else if (to_find > list[mid])
	{
		return binarySearch (list, to_find, mid+1, end_index);
	}
	else
	{
		// Not in the list
		return -1;
	}
}