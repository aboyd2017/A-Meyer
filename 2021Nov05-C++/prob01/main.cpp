#include <iostream>
#include "array_double.hpp"
#include "exception.hpp"

int main()
{
  int num_elements;
  int location;
  double value;
  std::cout << "Please enter the number of elements for your array: ";
  std::cin >> num_elements;

  try
  {
    ArrayDouble arr (num_elements);


    if (num_elements > 0)
    {
      std::cout << "Enter a value you would like to add to the array: ";
      std::cin >> value;
      std::cout << "Where would you like to add this number"
                << " (array index 0 to " << num_elements - 1 << ")? ";
      std::cin >> location;

      arr[location] = value;


      std::cout << "Value at location " << location << " now contains "
                << arr[location] << std::endl;
      arr.save();
    }

    arr.display();
    arr.save("final.txt");
  }
  catch (const IndexOutOfRangeException & e)
  {
    std::cout << e.getMessage() << std::endl;
  }
  catch (const InvalidArrayLengthException & e)
  {
    std::cout << e.getMessage() << std::endl;
  }
  catch (const Exception & e)
  {
    std::cout << "Unknown exception " << e.getMessage() << std::endl;
  }

  return 0;
}
