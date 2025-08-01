#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr, vector<vector<int>> &ans, size_t index) {

    // base case
    if(index >= arr.size()) {
        ans.push_back(arr);
        return;
    }

    for(size_t j = index; j < arr.size(); j++) {
        swap(arr[index], arr[j]);
        solve(arr, ans, index + 1);
        swap(arr[index], arr[j]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    solve(arr, ans, 0);

    // print all permutations
    cout << "All permutations:\n";
    for(const auto &perm : ans) {
        for(int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
