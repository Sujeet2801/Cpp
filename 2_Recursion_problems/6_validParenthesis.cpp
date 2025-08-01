// This corresponds to the Catalan number for n = 3, which is:
// C_n = \frac{1}{n+1} \binom{2n}{n} = \frac{1}{4} \binom{6}{3} = \frac{1}{4} \times 20 = 5

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive helper function
void solve(vector<string>& result, string current, int openLeft, int closeLeft) {

    if (openLeft == 0 && closeLeft == 0) {
        result.push_back(current);
        return;
    }

    if (openLeft > 0) {
        solve(result, current + "(", openLeft - 1, closeLeft);
    }

    if (closeLeft > openLeft) {
        solve(result, current + ")", openLeft, closeLeft - 1);
    }
}

// Main function to generate valid parentheses
vector<string> validParenthesis(int n) {
    
    vector<string> result;
    solve(result, "", n, n);
    return result;
}

int main() {

    int n = 4;
    vector<string> combinations = validParenthesis(n);

    cout << "Valid Parentheses Combinations for n = " << n << ":\n";

    for (const string& s : combinations) {
        cout << s << endl; 
    }

    return 0;
}
