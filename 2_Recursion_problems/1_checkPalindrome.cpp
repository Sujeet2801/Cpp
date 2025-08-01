#include<iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end){

    if(start >= end) return true;

    if(str[start] != str[end]){
        return false;
    }

    return checkPalindrome(str, start+1, end-1);
}

int main(){

    string str = "abcdba";
    bool result = checkPalindrome(str, 0, str.size()-1);
    if(result){
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not palindrome" << endl;
    }

    return 0;
}