#include<iostream>
using namespace std;

// Function to reverse a string recursively
string recursive_string(string name) {

    if(name.length() == 0) return "";
    return string(1, name[name.length() - 1]) + recursive_string(name.substr(0, name.length() - 1));
}

string recursive_string_alternate(string name){

    if(name.length() == 0) return "";
    return recursive_string_alternate(name.substr(0, name.length() - 1)) + string(1, name[name.length() - 1]);
}

// Recursive function to reverse a string (Approach 1: append last character first)
string reverseStringBackToFront(const string& str) {

    if (str.empty()) return "";
    return str.back() + reverseStringBackToFront(str.substr(0, str.size() - 1));
}

// Recursive function to reverse a string (Approach 2: append first character last)
string reverseStringFrontToBack(const string& str) {

    if (str.empty()) return "";
    return reverseStringFrontToBack(str.substr(1)) + str[0];
}

int main() {
    string name = "Hello";

    cout << "Original string: " << name << endl;
    cout << "Reversed string: " << recursive_string_alternate(name) << endl;

    return 0;
}