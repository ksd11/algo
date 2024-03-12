#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    int res = 1;
    int st = 0, ed = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      if (i != n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = 2;
        if (dp[i][i + 1] > res) {
          res = dp[i][i + 1];
          st = i;
          ed = i + 1;
        }
      }
    }

    for (int i = n-3; i >=0; i--) {
      for (int j = i + 2; j < n; j++) {
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
          if (dp[i][j] > res) {
            res = dp[i][j];
            st = i;
            ed = j;
          }
        }
      }
    }
    return s.substr(st, ed - st + 1);
  }
};