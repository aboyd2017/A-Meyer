#include <iostream>
#include "search.hpp"

int main()
{
  int my_array[SIZE] = {3, 6, 8, 9, 11, 15, 17, 18, 20, 22};
  int choice;
  std::cout << "Array: ";
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << my_array[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Please enter a number you want to search for: ";
  std::cin >> choice;

  // TODO:
  // Provide code that calls the `binarySearch` function to find the user's
  // `choice` in the array. Store the return value in a variable named
  // `index` so that the code below works
  int index = binarySearch (my_array, choice, 0, SIZE);


  if (index == -1)
  {
    std::cout << choice << " is not in the array\n";
  }
  else
  {
    std::cout << "The index of " << choice << " in the array is: " << index
              << std::endl;
  }

  return 0;
}
