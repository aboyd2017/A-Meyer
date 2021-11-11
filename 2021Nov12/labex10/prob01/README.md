# Recursion
In this lab you will create a recursive function.

Note: This problem seems easy to solve with a loop, but you ***must*** use recursion instead. This is to practice the thought process of coming up with a recursive solution. *You will not get credit for solving the problem without recursion, even if all the tests pass.*

## `recursion.cpp`
The only file you need to modify is `recursion.cpp`. Please implement the function `sumArray` in this file. You will find the function prototype for `sumArray` in the `recursion.hpp` file, and a program to test this function in `main.cpp`.

### `sumArray`
Create a recursive function named `sumArray` which adds together all elements of an `int` array, and returns that sum to the caller. This function receives two parameters, an array of integers and an int indicating the size of the array.

This function will return zero if the array is empty, or if an invalid size has been passed into the function for the array size. Otherwise, break the problem into smaller pieces by adding together one element of the array plus *(recursion)* the sum of the rest of the array.

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
Please select an option
 (S) sumArray
 (Q) quit
Your choice: <b>s</b>
What size is your array? (up to 10) 2
Enter an integer: <b>3</b>
Enter an integer: <b>4</b>
Calculating...
The sum is 7

Please select an option
 (S) sumArray
 (Q) quit
Your choice: <b>q</b>
</pre>
