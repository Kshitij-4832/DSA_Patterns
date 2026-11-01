#include <bits/stdc++.h>
using namespace std;
bool Valid(vector<vector<int>> &grid, int row, int col, int element) {
  for (int i = 0; i < 9; i++) {
    if (grid[row][i] == element) {
      return false;
    }
    if (grid[i][col] == element) {
      return false;
    }
    if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == element) {
      return false;
    }
  }
  cout << "----------------------------------------" << endl;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << "----------------------------------------" << endl;
  return true;
}
bool solve(vector<vector<int>> &grid) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        for (int k = 1; k <= 9; k++) {
          if (Valid(grid, i, j, k)) {
            grid[i][j] = k;
            if (solve(grid)) {
              return true;
            } else {
              grid[i][j] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}
int main() {
  vector<vector<int>> grid = {
      {5, 3, 0, 6, 7, 8, 9, 0, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8},
      {0, 9, 8, 3, 4, 2, 5, 6, 7}, {8, 5, 9, 7, 6, 1, 4, 2, 3},
      {4, 2, 6, 8, 5, 3, 7, 9, 0}, {7, 1, 3, 9, 0, 4, 8, 0, 6},
      {9, 6, 0, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5},
      {3, 4, 5, 2, 8, 6, 1, 7, 9}};

  solve(grid);
  return 0;
}