#include <iostream>
#include <vector>
#include <map>
using namespace std;

void backtrack(int index, const string& digits, map<char, string>& keypad, string current, vector<string>& result) {
    
    if (index == digits.length()) {
        result.push_back(current); 
        return;
    }

    char digit = digits[index];
    cout << "digit: " << digit << endl;
    for (char ch : keypad[digit]) {
        cout << "ch: " << ch << endl;
        backtrack(index + 1, digits, keypad, current + ch, result);
    }
}

vector<string> letterCombinations(const string& digits) {

    if (digits.empty()) return {};

    map<char, string> keypad = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> result; 
    backtrack(0, digits, keypad, "", result);
    return result;
}

int main() {
    
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);

    for (const string& word : combinations) {
        cout << word << " ";
    } cout << endl;

    return 0;
}
