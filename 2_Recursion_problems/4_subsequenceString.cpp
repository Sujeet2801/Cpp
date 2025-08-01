#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, size_t index, vector<string> &ans) {

    // base case
    if(index >= str.length()) {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(str, output, index + 1, ans);

    // include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

int main() {
    string str = "abc";
    string output = "";
    vector<string> ans;
    size_t index = 0;

    solve(str, output, index, ans);

    // print all subsequences
    cout << "All subsequences:\n";
    for(const string &s : ans) {
        cout << (s.empty() ? "\"\"" : s) << " ";
    }

    return 0;
}
