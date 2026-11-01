#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<string> &board, int col, int n,
            int row) {
  int duprow = row;
  int dupcol = col;
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row--;
    col--;
  }
  row = duprow;
  col = dupcol;
  while (col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    col--;
  }
  row = duprow;
  col = dupcol;
  while (row < n && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row++;
    col--;
  }
  return true;
}
void Solve(vector<vector<string>> &ans, vector<string> &board, int col, int n) {
  if (col == board.size()) {
    ans.push_back(board);
    return;
  }
  for (int row = 0; row < board.size(); row++) {
    if (isSafe (board, col, 4, row)) {
      board[row][col] = 'Q';
      Solve(ans, board, col + 1, 4);
      board[row][col] = '.';
    }
  }
  return ;
}
int main() {
  vector<vector<string>> ans;
  vector<string> board(4, "");
  string str(4, '.');
  for (int i = 0; i < 4; i++) {
    board[i] = str;
  }
  Solve(ans, board, 0, 4);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < 4; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}