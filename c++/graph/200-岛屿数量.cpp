#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  void bfs(vector<vector<char>> &grid, int i, int j) {
    if (grid[i][j] == '0')
      return;
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';

    while (!q.empty()) {
      auto pos = q.front();
      q.pop();

      for (auto &dir : direction) {
        auto x = dir.first;
        auto y = dir.second;

        auto xx = pos.first + x;
        auto yy = pos.second + y;
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') {
          grid[xx][yy] = '0';
          q.push({xx, yy});
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          res += 1;
          bfs(grid, i, j);
        }
      }
    }
    return res;
  }
};

int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    // vector<vector<char>> grid = {
    //     {'1','1',},
    //     {'1','0'},
    // };
    cout << Solution().numIslands(grid) << endl;
    return 0;
}