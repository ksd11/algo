#include <queue>
#include <vector>
using namespace std;

class Solution {
  int flag[10 + 1][10 + 1] = {0};
  pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      auto pos = q.front();
      q.pop();
      for (auto &dir : direction) {
        auto xx = pos.first + dir.first;
        auto yy = pos.second + dir.second;
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1) {
          grid[xx][yy] = 2;
          q.push({xx, yy});
          flag[xx][yy] = flag[pos.first][pos.second] + 1;
        }
      }
    }

    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1) return -1;
            res = max(res, flag[i][j]);
        }
    }
    return res;
  }
};