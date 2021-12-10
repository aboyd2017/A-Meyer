# Cellphone Application
The cellphone application stores basic information about a cell phone.

# Instructions
Part of the code has been provided for you. You will find "TODO" statements throughout the files with basic instructions of what goes there. However, this README file contains more detailed instructions for each of those portions of the code.

## main
Update the `main` function to do the following.
1. Create a `Cellphone` object using its non-default constructor. You can pass the string "Android" for the cell phone type, and "555-555-5555" for the cell phone number
1. Create a *pointer* to a `Speaker` object, and dynamically allocate memory for the pointer. Use the non-default constructor for the dynamically allocated `Speaker` and pass the string "Bose" for the brand of speaker
1. Call the `pair` function of the `Cellphone` object, and pass in the `Speaker` pointer as the argument
1. Call the `display` function of the `Cellphone` object
1. Free up memory that was allocated for the `Speaker` and set the pointer to `nullptr`

## Speaker class
The `Speaker` class has been provided for you. You do not need to modify this class.

## Cellphone class
Add a class named `Cellphone` that contains the following characteristics.
1. private data members - add three private data members
   - `std::string` to represent the type of phone
   - `std::string` to represent the phone number
   - `Speaker *` (pointer to a *Speaker* object) to represent the speaker that will be paired with the cell phone
1. constructor - create a public non-default constructor that accepts two constant references to `std::string` representing the cell phone type and number, and sets the private data members accordingly. In addition, this function should set the *pointer* private data member to `nullptr`
1. `pair` - create a public member function named `pair` that takes a <u>pointer</u> to a `Speaker` object, and does not return anything. This function sets the private data member pointer for the speaker
1. `display` - create a public member function named `display` that does not accept any parameters, nor does it return anything. Declare this function to be a constant function. This function prints out the cell phone type and number. In addition, if the speaker pointer has been set *(is not nullptr)*, then this function also prints out the name of the speaker. Otherwise, it prints "No speaker attached"

## Hints
1. Don't forget to declare `std::string` parameters as constant reference parameters for all member functions and constructors
1. For member functions that do not modify data members of the class, don't forget to declare these as constant functions

# Unit Test
This lab contains a unit test, which can be run by typing the following commands in the *Terminal* window. You can use the output from the unit tests to help debug any potential bugs in your program.
```
make build
make test
```

# Run Your Program
The `make build` command above creates an executable named `main`. Therefore, you do not need to run `clang++` for this lab. See the sample output below for what your program should print when you run it.
```
./main
```

# Sample Output
```
Android
555-555-5555
Bose speaker
```
