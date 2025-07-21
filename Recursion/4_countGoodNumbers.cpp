#include <iostream>
#include <string>
using namespace std;

// Efficient exponentiation (Exponentiation by Squaring)
int power(int base, int exponent) {
    if (exponent == 0) return 1;

    int half = power(base, exponent / 2);
    int result = half * half;

    if (exponent % 2 == 1)
        result *= base;

    return result;
}

// Calculates the count of "good strings" based on even/odd position constraints
int countGoodStrings(const string& str) {
    int length = str.length();
    int evenCount = (length + 1) / 2; 
    int oddCount = length / 2;        

    return power(5, evenCount) * power(4, oddCount);
}

int main() {
    string name = "2345";
    int result = countGoodStrings(name);

    cout << "Count: " << result << endl;
    return 0;
}
