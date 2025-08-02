#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited ){

    if((x >= 0 && x < n) && (y >= 0 && y < n) && (maze[x][y] == 1) && (visited[x][y] == 0)){
        return true;
    }

    return false;
}

// Using for loop
void solve2(int x, int y, int n, vector<vector<int>> &maze,
           vector<vector<bool>> &visited, string path, vector<string> &result) {
    
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Directions: Down, Left, Right, Up
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isSafe(newX, newY, n, maze, visited)) {
            solve(newX, newY, n, maze, visited, path + dir[i], result);
        }
    }

    visited[x][y] = 0; // Backtrack
}

void solve(int x, int y, int n, vector<vector<int>> &maze,
           vector<vector<bool>> &visited, string path, vector<string> &result) {
    
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, n, maze, visited))
        solve(x + 1, y, n, maze, visited, path + "D", result);
    
    // Left
    if (isSafe(x, y - 1, n, maze, visited))
        solve(x, y - 1, n, maze, visited, path + "L", result);
    
    // Right
    if (isSafe(x, y + 1, n, maze, visited))
        solve(x, y + 1, n, maze, visited, path + "R", result);
    
    // Up
    if (isSafe(x - 1, y, n, maze, visited))
        solve(x - 1, y, n, maze, visited, path + "U", result);

    visited[x][y] = 0; // Backtrack
}

vector<string> ratInMaze(vector<vector<int>> &maze){

    vector<string> result;
    int n = maze.size();

    vector<vector<bool>> visited (n,vector<bool> (n,0));
    
    string path = "";
    solve(0, 0, n, maze, visited, path, result);
    return result;
}

int main() {

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = ratInMaze(maze);

    if (result.empty()) {
        cout << "-1\n";
    } else {
        for (const auto& p : result) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}