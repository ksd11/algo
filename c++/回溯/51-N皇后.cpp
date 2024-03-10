#include <iostream>
#include <vector>
using namespace std;

class Solution {
  bool occupy_column[10] = {false};
  bool occupy_diag[40] = {false}; // i+j   i-j+3n
  int pos[10];
  vector<vector<string>> res;

  void dfs(int n, int k) {
    if (n == k) {
      vector<string> vec;
      for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
          if (pos[i] == j)
            s += "Q";
          else
            s += ".";
        }
        vec.push_back(s);
      }
      res.push_back(vec);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (occupy_column[i] || occupy_diag[k + i] || occupy_diag[k - i + 3 * n])
        continue;
      occupy_column[i] = occupy_diag[k + i] = occupy_diag[k - i + 3 * n] = true;
      pos[k] = i;
      dfs(n, k + 1);
      occupy_column[i] = occupy_diag[k + i] = occupy_diag[k - i + 3 * n] =
          false;
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    dfs(n, 0);
    return res;
  }
};