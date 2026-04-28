# Introduction to Recursion

The process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called a recursive function.

A recursive algorithm takes one step toward solution and then recursively call itself to further move. The algorithm stops once we reach the solution.

Since called function may further call itself, this process might continue forever. So it is essential to provide a base case to terminate this recursion process.

## Steps to Implement Recursion

***Step1*** - **Define a base case:** Identify the simplest (or base) case for which the solution is known or trivial. This is the stopping condition for the recursion, as it prevents the function from infinitely calling itself.

***Step2*** - **Define a recursive case:** Define the problem in terms of smaller subproblems. Break the problem down into smaller versions of itself, and call the function recursively to solve each subproblem.

***Step3*** - **Ensure the recursion terminates:** Make sure that the recursive function eventually reaches the base case, and does not enter an infinite loop.

***Step4*** - **Combine the solutions: **Combine the solutions of the subproblems to solve the original problem.

## When does Stack Overflow error occur in recursion? 

If the base case is not reached or not defined, then the stack overflow problem may arise. Let us take an example to understand this.

```
int fact(int n)
{
    // wrong base case (it may cause stack overflow).
    if (n == 100) 
        return 1;
    else
        return n*fact(n-1);
} 
```

- In this example, if fact(10) is called, the function will recursively call fact(9), then fact(8), fact(7), and so on. However, the base case checks if n == 100. Since n will never reach 100 during these recursive calls, the base case is never triggered. As a result, the recursion continues indefinitely.

- This continuous recursion consumes memory on the function call stack. If the system's memory is exhausted due to these unending function calls, a stack overflow error occurs.

- To prevent this, it's essential to define a proper base case, such as if (n == 0) to ensure that the recursion terminates and the function doesn't run out of memory.

## What is the difference between direct and indirect recursion? 

A function is called direct recursive if it calls itself directly during its execution. In other words, the function makes a recursive call to itself within its own body.

An indirect recursive function is one that calls another function, and that other function, in turn, calls the original function either directly or through other functions. This creates a chain of recursive calls involving multiple functions, as opposed to direct recursion, where a function calls itself.

```
// An example of direct recursion
void directRecFun()
{
    // Some code....

    directRecFun();

    // Some code...
}

// An example of indirect recursion
void indirectRecFun1()
{
    // Some code...

    indirectRecFun2();

    // Some code...
}
void indirectRecFun2()
{
    // Some code...

    indirectRecFun1();

    // Some code...
}
```

## How memory is allocated to different function calls in recursion? 

Recursion uses more memory to store data of every recursive call in an internal function call stack.

Whenever we call a function, its record is added to the stack and remains there until the call is finished.
The internal systems use a stack because function calling follows LIFO structure, the last called function finishes first.

## What are the advantages of recursive programming over iterative programming? 

- Recursion provides a clean and simple way to write code.

- Some problems are inherently recursive like tree traversals, Tower of Hanoi, etc. For such problems, it is preferred to write recursive code. We can write such codes also iteratively with the help of a stack data structure. 

## What are the disadvantages of recursive programming over iterative programming?

**Note:** Every recursive program can be written iteratively and vice versa is also true.

- Recursive programs typically have more space requirements and also more time to maintain the recursion call stack.

- Recursion can make the code more difficult to understand and debug, since it requires thinking about multiple levels of function calls.

## Common Applications of Recursion

- **Tree and Graph Traversal:** Used for systematically exploring nodes/vertices in data structures like trees and graphs.

- **Sorting Algorithms:** Algorithms like quicksort and merge sort divide data into subarrays, sort them recursively, and merge them.

- **Divide-and-Conquer Algorithms:** Algorithms like binary search break problems into smaller subproblems using recursion.

- **Fractal Generation:** Recursion helps generate fractal patterns, such as the Mandelbrot set, by repeatedly applying a recursive formula.

- **Backtracking Algorithms:** Used for problems requiring a sequence of decisions, where recursion explores all possible paths and backtracks when needed.

- **Memoization:** Involves caching results of recursive function calls to avoid recomputing expensive subproblems.


# Tail Recursion & Tail Call Elimination (TCE)

## Tail Recursion
A function is **tail recursive** if the recursive call is the **last operation**.

### Example
```cpp
void fun(int n) {
    if (n == 0) return;
    fun(n - 1);  // last statement → tail recursion
}
```

## Non-Tail Recursive
```
void fun(int n) {
    if (n == 0) return;
    fun(n - 1);
    cout << n;   // work after recursion → not tail recursive
}
```

## Tail Call Elimination (TCE)
**Definition: **
An optimization where the compiler replaces tail recursion with a loop, avoiding extra stack usage.

**Key Idea:**
- Recursive call is replaced with iteration
- No new stack frames created

**Space Complexity:**
- Without TCE → O(N)
- With TCE → O(1)

### QuickSort Optimization
```
while (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    low = pi + 1;  // tail call eliminated
}
```

### Conditions for TCE
- Recursive call must be last
- No operations after call
- Return value directly returned