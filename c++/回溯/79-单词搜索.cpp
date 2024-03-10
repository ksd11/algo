#include <iostream>
#include <vector>
using namespace std;

class Solution {
  pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int m;
  int n;
  int success = false;
  bool is_visited[6][6] = {false};

  void dfs(string &s, int i, int j, vector<vector<char>> &board, int idx) {

    if (idx == s.size()) {
      success = true;
      return;
    }
    for (auto &dir : direction) {
      int xx = i + dir.first;
      int yy = j + dir.second;
      if (xx < 0 || xx >= m || yy < 0 || yy >= n)
        continue;
      if (!is_visited[xx][yy] && board[xx][yy] == s[idx]) {
        is_visited[i][j] = true;
        dfs(s, xx, yy, board, idx + 1);
        is_visited[i][j] = false;
        if(success) return;
      }
    }
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    m = board.size();
    n = board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            if(board[i][j] == word[0]){
                is_visited[i][j] = true;
                dfs(word, i, j, board, 1);
                is_visited[i][j] = false;
                if(success) return true;
            }
        }
    }
    return false;
  }
};

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution().exist(board, "ABCCED");
    return 0;
}