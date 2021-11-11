#include "recursion.hpp"


int sumArray(int array[], int size)
{
	int sum = 0;

	// Return 0 if empty
	if (size == 0)
	{
		return 0;
	}


	// Otherwise, add the last element to the sum of the rest of the array
	sum = sumArray(array, size - 1) + array[size-1];

	return sum;
}