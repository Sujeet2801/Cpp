#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Efficient exponentiation
int power(int base, int exponent) {
    if (exponent == 0) return 1;
    int half = power(base, exponent / 2);
    int result = half * half;
    if (exponent % 2 == 1) result *= base;
    return result;
}

// Check if string follows the good string rule
bool isValidGoodString(const string& str) {
    unordered_set<char> evenAllowed = {'0', '2', '4', '6', '8'};
    unordered_set<char> primeAllowed = {'2', '3', '5', '7'};

    for (size_t i = 0; i < str.length(); ++i) {
        if (i % 2 == 0 && evenAllowed.find(str[i]) == evenAllowed.end()) { // evenAllowed.count(str[i]) == 0)
            return false;
        }
        if (i % 2 == 1 && primeAllowed.find(str[i]) == primeAllowed.end()) {
            return false;
        }
    }
    return true;
}

// Count good strings
int countGoodStrings( string& str) {
    int length = str.length();
    int evenCount = (length + 1) / 2;
    int oddCount = length / 2;
    return power(5, evenCount) * power(4, oddCount);
}

int main() {
    string name = "2345";

    if (isValidGoodString(name)) {
        cout << "Valid String ✅" << endl;
    } else {
        cout << "Invalid String ❌" << endl;
        return 0;
    }

    int result = countGoodStrings(name);
    cout << "Count: " << result << endl;

    return 0;
}
