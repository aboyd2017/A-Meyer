# Array Exceptions
You will be creating a program that throws and catches exceptions. The focus of this exercise is to demonstrate exception handling, with an operator overloading treat.

## `exception.hpp` file
This file contains multiple types of exception classes.

### `Exception` class
This class is the base class (parent) for other specific exceptions that your program will handle.

#### Class members
The `Exception` class contains one data member which is a `std::string` variable to hold the exception message.

It also contains an accessor and a mutator for the message.

#### Constructors
The `Exception` class contains a public non-default constructor that accepts a `std::string` *(constant reference)* to set the message data member. In addition, it contains a protected default constructor so that only subclasses of this base class can instantiate an `Exception` with no message text.

### `IndexOutOfRangeException` class
This class inherits from the `Exception` class, but has its own specific exception message.

*Note: this class has been provided for you.*

#### Constructors
The `IndexOutOfRangeException` class contains only one constructor. This constructor is a public non-default constructor that accepts two `int` parameters which represent the index and size of the array. These are used to set the exception message.

### `InvalidArrayLengthException` class
This class inherits from the `Exception` class, but has its own specific exception message.

#### Constructors
The `InvalidArrayLengthException` class should contain only one constructor. This constructor is a public non-default constructor that accepts one `int` parameter which represents the number of elements in the array. This value should be used in the exception message.

You need to create this constructor, which should set the exception message for this class. See the sample output below for the content and format of the exception message. And you can use the non-default constructor in the other exception class as a model for implementation of this constructor.

## `array_double.hpp` file
Don't forget to protect this header file with *include guards* so that it will not be included more than once in your program. For example:
```
#ifndef __NAME_OF_FILE_HPP__
#define __NAME_OF_FILE_HPP__
<<your header file code goes here>>
#endif
```

### Constants
Please create a constant string named DEFAULT_FILENAME that is set to "doubles.txt"
This is the name of the file your class will write its array to.

### `ArrayDouble` class
This class holds an array of doubles, and offers functions to perform actions with the array.

#### Data members
The `ArrayDouble` class should contain the following private data members:
1. `_array` which is a pointer to a `double` and represents the array of doubles
1. `_count` which is an `int` and represents the number of elements in the array

#### Constructor
The `ArrayDouble` class should contain only one constructor, which is a public non-default constructor that accepts one `int` parameter which represents the number of elements in the array.

The body of this constructor should be implemented in the `array_double.cpp` file; therefore, the description for this constructor is below.

#### Destructor
The `ArrayDouble` class destructor should deallocate the memory that was allocated for the `_array`.

#### Member functions
The `ArrayDouble` class should contain the following member functions. The function prototypes for these functions sould go in the header file, and the implementation of the functions in the source file. The function descriptions are below in the `array_double.cpp` section.
1. overloaded `operator[]` to access elements in the array
   - *function prototype:* double & operator[](int ix) const;
1. `display` which is a constant function that takes no parameters and returns void
1. `save` which is a constant function that takes one string parameter *(constant reference)* and does not return anything. Provide a default value for the parameter so that the parameter is optional. Set the default value to `DEFAULT_FILENAME`.

## `array_double.cpp` file
This file contains functions for the `ArrayDouble` class.

### `ArrayDouble` Class Constructor
The member initialization list for the constructor should set the `_array` pointer to `nullptr` and the value of `_count` to `0`. This way they have been set to valid values in case the function throws an exception.

In the body of this constructor, it should throw an `InvalidArrayLengthException` if the value of the parameter is less than zero.

Otherwise, the parameter value is valid, in which case, set the data members as follows:
1. `_count` should be set to the value of the parameter.
1. `_array` should be set to a dynamically allocated array of `double` using the value of the parameter as the number of elements in the array. Make sure the value is greater than zero before allocating the array, and be sure to initialize all values in the array to zero. *(You can do this using array initialization `{0}`)*

### `ArrayDouble::operator[]`
The overloaded `operator[]` function will provide an index into the array. This function receives a parameter representing an index in the array, and should throw an `IndexOutOfRangeException` if the index does not fall within the valid range for the array elements.

If the index is valid, then the function should return the value of the array at that index.

### `ArrayDouble::save`
This function writes to the file with the name specified in the parameter. It *appends* the contents of the array onto the end of the file. Be sure that every time your program runs, the file continues to grow larger.

The format of the output should simply be all doubles in your array, with 2 digits past the decimal for each, and separated by a space between each. For example:
```
0.00 3.12 0.00
```
If the array is empty, then this function should not print anything to the file.

### `ArrayDouble::display`
This function displays the contents of the array to the console, with 2 digits past the decimal for all `double` values. See the sample output below for the format of the string displayed. If the array has not yet been allocated, this function should display `Array is empty.`

*Note: this function has been provided for you.*

## `main.cpp` file
Complete the `main` function as described in the `TODO` statements `main.cpp`. Follow the sample output as closely as possible. Keep in mind <b>bold</b> values in the samples represent user input.

# Unit Test
This lab contains a unit test, which can be run by typing the following commands in the *Terminal* window. You can use the unit test output to help debug your program.
```
make build
make test
```

# Run Your Program
The `make build` command above creates an executable named `main`. Therefore, you do not need to run `clang++` for this lab. See the sample output below for what your program should print when you run it.
```
./main
```

# Sample Output 1
<pre>
Please enter the number of elements for your array: <b>5</b>
Enter a value you would like to add to the array: <b>2.2</b>
Where would you like to add this number (array index 0 to 4)? <b>1</b>
Value at location 1 now contains 2.2
Array contents: 0.00 2.20 0.00 0.00 0.00
</pre>

# Sample Output 2
<pre>
Please enter the number of elements for your array: <b>0</b>
Array is empty.
</pre>

# Sample Output (invalid number of elements)
<pre>
Please enter the number of elements for your array: <b>-2</b>
Invalid number of elements (-2). Value must be a positive integer.
</pre>

# Sample Output (invalid array index)
<pre>
Please enter the number of elements for your array: <b>3</b>
Enter a value you would like to add to the array: <b>4.2</b>
Where would you like to add this number (array index 0 to 2)? <b>3</b>
Invalid index 3 for an array with 3 elements. Value must be between 0 and 2.
</pre>
