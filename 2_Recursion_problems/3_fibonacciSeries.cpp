#include <iostream>
#include <cstring>  // for memset
using namespace std;

const int MAX = 101;
int memo[MAX];

// Correct Memoization Version
int fibonacciMemoization(int num) {
    if (num <= 1) return num;

    if (memo[num] != -1) return memo[num];

    return memo[num] = fibonacciMemoization(num - 1) + fibonacciMemoization(num - 2);
}

// Simple Recursive Version (Exponential Time)
int fibonacciRecursive(int num) {
    if (num <= 1) return num;
    return fibonacciRecursive(num - 1) + fibonacciRecursive(num - 2);
}

// Tail-Recursive Fibonacci Printer
void printFibonacci(int a, int b, int count, int limit) {
    if (count >= limit) return;
    cout << a << " ";
    printFibonacci(b, a + b, count + 1, limit);
}

// Iterative Fibonacci Sequence Printer
void fibonacciIterative(int num) {
    int a = 0, b = 1;

    for (int i = 0; i < num; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int num = 10;

    // Initialize memo array with -1
    memset(memo, -1, sizeof(memo));

    cout << "Fibonacci using simple recursion (num = " << num << "): " << fibonacciRecursive(num) << endl;

    cout << "Fibonacci using memoization (num = " << num << "): " << fibonacciMemoization(num) << endl;

    cout << "Fibonacci series using tail-recursion: ";
    printFibonacci(0, 1, 0, num);
    cout << endl;

    cout << "Fibonacci series using iteration: ";
    fibonacciIterative(num);

    return 0;
}
