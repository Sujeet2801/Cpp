#include <iostream>
#include <vector>
using namespace std;

void findCombinations(size_t index, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {

    if (target == 0) {
        result.push_back(current);
        return;
    }

    if (index == candidates.size() || target < 0) {
        return;
    }

    // Include the current number (can reuse)
    if (candidates[index] <= target) {
        current.push_back(candidates[index]);
        findCombinations(index, target - candidates[index], candidates, current, result);
        current.pop_back();  // backtrack
    }

    // Exclude the current number and move to next
    findCombinations(index + 1, target, candidates, current, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(0, target, candidates, current, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 4};
    int target = 8;

    vector<vector<int>> combinations = combinationSum(candidates, target);

    for (const auto& combo : combinations) {
        cout << "[ ";
        for (int num : combo)
            cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
