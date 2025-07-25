#include <iostream>
using namespace std;

// Iterative function to calculate sum of array elements
int sumIterative(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Recursive function to calculate sum of array elements
int sumRecursive(const int arr[], int size) {
    if (size == 0) return 0;
    return arr[0] + sumRecursive(arr + 1, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Sum (Iterative): " << sumIterative(arr, size) << endl;
    cout << "Sum (Recursive): " << sumRecursive(arr, size) << endl;

    return 0;
}
