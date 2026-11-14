#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 0;
  cin >> n;
  vector<int> arr(n + 1, 1);
  for (int i = 2; i < arr.size(); i++) {
    for (int j = i * i; j < arr.size(); j = j + i) {
      if (arr[j] == 1) {
        arr[j] = 0;
      }
    }
  }
  int count = 0;
  for (int i = 2; i < n + 1; i++) {
    if (arr[i] == 1) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}