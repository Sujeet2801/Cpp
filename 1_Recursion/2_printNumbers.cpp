#include<iostream>
using namespace std;

void printNumber(int x){

    if(x == 0) return ;

    printNumber(x-1);
    cout << x << " ";
}

int main(){

    int number = 5;
    printNumber(number);

    return 0;
}