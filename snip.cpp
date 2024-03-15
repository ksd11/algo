#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct pair_hash {
  template <class T1, class T2>
  size_t operator()(pair<T1, T2> const &pair) const {
    size_t h1 =
        hash<T1>()(pair.first);  // 用默认的 hash 处理 pair 中的第一个数据 X1
    size_t h2 =
        hash<T2>()(pair.second);  // 用默认的 hash 处理 pair 中的第二个数据 X2
    return (h1 >> 17) ^ (h2 << 15);
  }
};

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
