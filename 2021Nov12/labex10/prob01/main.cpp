#include <iostream>
#include "recursion.hpp"

int main()
{
  char choice;
  do
  {
    std::cout << "\nPlease select an option\n"
              << " (S) sumArray\n"
              << " (Q) quit\n"
              << "Your choice: ";
    std::cin >> choice;

    if (choice == 's' || choice == 'S')
    {
      int size;
      std::cout << "What size is your array? (up to " << MAX_ARRAY << ") ";
      std::cin >> size;
      int array[size];
      for (int i = 0; i < size; i++)
      {
        int value;
        std::cout << "Enter an integer: ";
        std::cin >> value;
        array[i] = value;
      }
      std::cout << "Calculating..." << std::endl;
      int sum = sumArray(array, size);
      std::cout << "The sum is " << sum << std::endl;
    }
  } while (choice != 'q' && choice != 'Q');

  return 0;
}
