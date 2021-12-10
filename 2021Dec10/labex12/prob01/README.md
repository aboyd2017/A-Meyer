# Sports Application
The sports application fills two bobsledding teams with athletes to compete against each other, and also fills slots for two badminton athletes to compete against each other.

# Instructions
Part of the code has been provided for you. You will find "TODO" statements throughout the files with basic instructions of what goes there. However, this README file contains more detailed instructions for each of those portions of the code.

## main
Note that the `main()` function has mostly been provided for you. Find the two "TODO" statements in there and add the code described in the comment for the "TODO".

## Sport class
A shell for the Sport class has been provided for you. You need to add two pure virtual functions called `enroll` and `display` to the class, as described below.
1. `enroll` - create a pure virtual function called `enroll` that contains one parameter, a constant reference to a `std::string` representing an athlete's name, and does not return anything.
1. `display` - create a pure virtual function called `display` that does not accept any parameters, nor does it return anything. Declare this function to be a constant function.

## Competitive class
Add a class named `Competitive` that inherits from `Sport`. A competitive sport is one where one athlete competes against another in a singles match.
1. private data members - add two private data members, both of type `std::string` to represent the names of the two athletes who will be competing against each other
1. `enroll` - override the parent `enroll` function. This function adds both athletes to the competition, one at a time. The first time `enroll` is called, it will set the value of the first private data member based on the name received in the parameter. The second time `enroll` is called it will set the value of the second data member. If both names have already been set, then display an error message
   - Hint: to determine whether a `std::string` object has been set to a value, you can use either the `empty` *(returns a bool)* or the `length` *(returns an int)* function for the object
1. `display` - override the parent `display` function. This function prints out the names of the two athletes competing against each other in the format: Name1 vs. Name2

## Team class
The `Team` class has been provided for you. You do not need to modify this class. A team sport is one where a team of athletes compete against another team with the same number of athletes.

## Athlete class
Add a class named `Athlete` that contains the following characteristics.
1. private data member - add a private data member of type `std::string` to represent the name of the athlete
1. constructor - create a public non-default constructor that accepts a constant reference to a `std::string` representing the athlete's name, and sets the private data member to that name
1. `join` - create a member function named `join` that takes a <u>pointer</u> to a `Sport` object, and does not return anything. This function calls the `enroll` function for the sport to enroll the `Athlete` in that sport

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
Dudley Stokes, Devon Harris, Michael White, Chris Stokes vs. Takao Sakai, Toshio Wakita, Yuji Yaku, Naomi Takewaki
Tai Tzu-ying vs. Chen Yufei
Both teams are full
Both athletes have already been registered
```
