#include <iostream>
using namespace std;

int power(int base, int exponent){

    if(exponent == 0){
        return 1;
    }

    int half = power(base, exponent / 2);
    int result = half * half;

    if(exponent % 2 == 1){
        result = result * base;
    }

    return result;
}

// Recursive function to calculate power of 2
int powerOf2(int exponent) {

    if (exponent < 0) {
        cerr << "Exponent must be non-negative." << endl;
        return -1;
    }
    if (exponent == 0) return 1;

    return 2 * powerOf2(exponent - 1);
}

int main() {
    int exponent;
    cout << "Enter a non-negative integer exponent: ";
    cin >> exponent;

    int result = power(2, exponent);
    if (result != -1) {
        cout << "2 raised to the power " << exponent << " is: " << result << endl;
    }

    return 0;
}
