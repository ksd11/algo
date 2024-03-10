#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 打印二维数组
void print2D(vector<vector<int>> res) {
  for (auto &vec : res) {
    for (auto &i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void print1D(vector<int> res) {
  for (auto &i : res) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  // print(Solution().combinationSum(candidates, target));
  return 0;
}
