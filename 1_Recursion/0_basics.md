# Definition
Recursion is a programming technique where a function calls itself to solve smaller instances of a problem until it reaches a base case.

# Rule of Thumb
Use recursion for problems with recursive substructure, hierarchical/nested data, or where code clarity matters.

Use iteration for simple repetitive tasks or when performance/memory are critical.

# Types
1. Head recursion 
2. Tail recursion

# Memoization Explained

## Definition:
Memoization is an optimization technique used to speed up recursive functions by storing the results of expensive function calls and reusing them when the same inputs occur again.

## Why Use Memoization?
Recursive algorithms (like Fibonacci, climbing stairs, etc.) may recalculate the same subproblems multiple times. Memoization avoids this by caching results.