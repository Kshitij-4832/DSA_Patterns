#include <bits/stdc++.h>
using namespace std;

void Solve(vector<string> &ans, vector<vector<int>> &maze,
           vector<vector<int>> &visited, int i, int j, int n, int m,
           string temp) {
  if (i == n - 1 && j == n - 1) {
    ans.push_back(temp);
    return;
  }

  // Downward
  if (i + 1 < n && visited[i + 1][j] == 0 && maze[i + 1][j] == 1) {
    visited[i][j] = 1;
    Solve(ans, maze, visited, i + 1, j, n, m, temp + 'D');
    visited[i][j] = 0;
  }
  // Leftward
  if (j - 1 >= 0 && visited[i][j - 1] == 0 && maze[i][j - 1] == 1) {
    visited[i][j] = 1;
    Solve(ans, maze, visited, i, j - 1, n, m, temp + 'L');
    visited[i][j] = 0;
  }
  // Rightward
  if (j + 1 < m && visited[i][j + 1] == 0 && maze[i][j + 1]==1) {
    visited[i][j] = 1;
    Solve(ans, maze, visited, i, j + 1, n, m, temp + 'R');
    visited[i][j] = 0;
  }
  // Upward
  if (i - 1 >= 0 && visited[i - 1][j] == 0 && maze[i - 1][j] == 1) {
    visited[i][j] = 1;
    Solve(ans, maze, visited, i - 1, j, n, m, temp + 'U');
    visited[i][j] = 0;
  }
}

int main() {
  vector<string> ans;
  vector<vector<int>> maze = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1}
};
  vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
  int n = maze.size();
  int m = maze[0].size();
  Solve(ans, maze, visited, 0, 0, n, m, "");
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}