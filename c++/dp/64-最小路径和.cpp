#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    const int INF = 1e9 + 7;
    vector<vector<int>> dp(m, vector(n, INF));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]+grid[i][j]);
        if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]+grid[i][j]);
      }
    }
    return dp[m-1][n-1];
  }
};