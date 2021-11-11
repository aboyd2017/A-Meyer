# Recursive Search
In this lab you will complete a recursive binary search function.

Note: This problem seems easy to solve with a loop, but you ***must*** use recursion instead. This is to practice the thought process of coming up with a recursive solution. *You will not get credit for solving the problem without recursion, even if all the tests pass.*

## `search.hpp`
This file contains the function prototype for the `binarySearch` function. You do not need to modify this file.

## `search.cpp`
Please implement the `binarySearch` function in this file.

### `binarySearch`
Create a recursive function named `binarySearch` that receives an integer array (`int array[]`) and a number to find in the array, as well as the start_index and end_index into the array. These indexes indicate the "search area" (i.e., the array indexes between *start* and *end* will be searched). The function should return the index of the number in the array if it exists between the *start* and *end*, and returns -1 if it isn't in the array.

Please follow a *binary search* algorithm, which splits the array in half, and *recursively* searches only half of the array with each *recursive* call. Note that for a binary search to work, the array must be sorted already, and

## `main.cpp`
The `main` function already contains most of its code implemented for you. You will find one `TODO` statment in `main.cpp` which instructs you to call the `binarySearch` recursive function.

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
<pre>
Array: 3 6 8 9 11 15 17 18 20 22
Please enter a number you want to search for: <b>17</b>
The index of 17 in the array is: 6
</pre>
