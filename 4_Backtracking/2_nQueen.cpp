/*
#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check row on left side
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    // Check upper-left diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // Check lower-left diagonal
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> solutions = nQueens(n);

    cout << "Total Solutions: " << solutions.size() << "\n";
    for (auto &sol : solutions) {
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
            if ((i + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n,
           vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag) {
    
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
            board[row][col] = 1;
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;

            solve(col + 1, ans, board, n, leftRow, upperDiag, lowerDiag);

            board[row][col] = 0;
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    vector<int> leftRow(n, 0);
    vector<int> upperDiag(2 * n - 1, 0);
    vector<int> lowerDiag(2 * n - 1, 0);

    solve(0, ans, board, n, leftRow, upperDiag, lowerDiag);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> solutions = nQueens(n);

    cout << "Total Solutions: " << solutions.size() << "\n";
    for (auto &sol : solutions) {
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
            if ((i + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }

    return 0;
}
