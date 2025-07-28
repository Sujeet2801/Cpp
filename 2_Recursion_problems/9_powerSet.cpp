#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &arr, vector<int> &output, size_t index, vector<vector<int>> &ans) {

    // base case
    if(index >= arr.size()) {
        ans.push_back(output);
        return;
    }

    // exclude the current element
    solve(arr, output, index + 1, ans);

    // include the current element
    output.push_back(arr[index]);
    solve(arr, output, index + 1, ans);
    output.pop_back();
}

int main() {

    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans;
    vector<int> output;
    size_t index = 0;

    solve(arr, output, index, ans);

    // print all subsets
    cout << "All subsets:" << endl;
    for(auto subset : ans) {
        cout << "[ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
