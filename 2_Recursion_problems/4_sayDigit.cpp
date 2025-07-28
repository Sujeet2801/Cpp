#include<iostream>
using namespace std;

void sayDigit(int digit){

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(digit == 0) return ;
    sayDigit(digit / 10);
    cout << arr[digit % 10] << " ";
}

int main(){

    int digit = 214;
    sayDigit(digit);

    return 0;
}