#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    if(numRows >= 2)
        res.push_back({1, 1});
    for (int i = 2; i < numRows; i++) {
      vector<int> tmp;
      tmp.push_back(1);
      for (int j = 1; j < i; j++) {
        tmp.push_back(res[i-1][j - 1] + res[i-1][j]);
      }
      tmp.push_back(1);
      res.push_back(tmp);
    }
    return res;
  }
};