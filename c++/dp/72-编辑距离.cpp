#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  // word1 -> word2
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    if (m == 0) return n;
    if (n == 0) return m;
    const int INF = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          if (i == 0 && j == 0)
            dp[i][j] = 1 - int(word1[0] == word2[0]);
          else if (i == 0) {
            if (word1[i] == word2[j])
              dp[i][j] = j;
            else
              dp[i][j] = dp[i][j - 1] + 1;
          } else {
            if (word1[i] == word2[j])
              dp[i][j] = i;
            else
              dp[i][j] = dp[i - 1][j] + 1;
          }
        } else {
          if (word1[i] == word2[j])
            dp[i][j] = dp[i - 1][j - 1];
          else {
            // 插入， 删除， 修改
            dp[i][j] =
                min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
          }
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

#include <iostream>
int main() {
  cout << Solution().minDistance("intention", "execution");
  return 0;
}