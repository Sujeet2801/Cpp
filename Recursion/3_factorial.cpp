#include<iostream>
#include <chrono>
using namespace std;
using namespace chrono;
const int MAX = 100;
long long memo[MAX];

long long factorial_iterative(int num){
    long long result = 1;

    for(int i=1; i<=num; i++){
        result *= i;
    }
    return result;
}

long long factorial_recursive(int num){

    if(num == 1){
        return 1;
    }

    return num * factorial_recursive(num-1);
}

long long factorial_memoization(int num){

    if(num <= 1){
        return 1;
    }

    if(memo[num] != -1 ){
        return memo[num];
    }

    memo[num] = num * factorial_memoization(num -1);
    return memo[num];
}

int main(){

    for(int i=0; i<MAX; i++){
        memo[i] = -1;
    }

    int number = 10;

    auto start = high_resolution_clock::now();

    // Run recursive function
    long long result = factorial_memoization(number);

    // Stop timer
    auto stop = high_resolution_clock::now();

    // Calculate duration in microseconds
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Output result and time
    cout << "Factorial of " << number << " is: " << result << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}

/*
#include <iostream>
#include <chrono>
#include <cstring> // For memset

using namespace std;
using namespace chrono;

const int MAX = 100;
long long memo[MAX];

// Iterative factorial (non-recursive, fast and safe)
long long factorialIterative(int num) {
    long long result = 1;
    for (int i = 2; i <= num; ++i)
        result *= i;
    return result;
}

// Basic recursive factorial (not suitable for large n)
long long factorialRecursive(int num) {
    if (num <= 1)
        return 1;
    return num * factorialRecursive(num - 1);
}

// Recursive factorial with memoization (Top-down DP)
long long factorialMemoization(int num) {
    if (num <= 1)
        return 1;
    if (memo[num] != -1)
        return memo[num];
    return memo[num] = num * factorialMemoization(num - 1);
}

// Measure execution time of a function
template<typename Func>
void benchmark(Func func, int num, const string& label) {
    auto start = high_resolution_clock::now();
    long long result = func(num);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << label << " Factorial of " << num << " = " << result << "\n";
    cout << "Time taken by " << label << ": " << duration.count() << " ns\n\n";
}

int main() {
    int number = 10;

    // Clear memoization table
    memset(memo, -1, sizeof(memo));

    benchmark(factorialIterative, number, "Iterative");
    benchmark(factorialRecursive, number, "Recursive");
    benchmark(factorialMemoization, number, "Memoized");

    return 0;
}
*/