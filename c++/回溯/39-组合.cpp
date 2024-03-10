#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  vector<vector<int>> res;
  void dfs(vector<int> &candidates, int k, int sum, vector<int> &vec) {
    int size = candidates.size();

    if (sum == 0) {
      res.push_back(vec);
      return;
    }
    if (k >= size)
      return;
    if (candidates[k] > sum)
      return;

    // 剪枝
    if (k == size - 1) {
      if (sum % candidates[k] == 0) {
        auto tmp = sum / candidates[k];
        for (int i = 0; i < tmp; i++) {
          vec.push_back(candidates[k]);
        }
        res.push_back(vec);
        for (int i = 0; i < tmp; i++) {
          vec.pop_back();
        }
      }
      return;
    }

    int n = sum / candidates[k];

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        vec.push_back(candidates[k]);
      }
      dfs(candidates, k + 1, sum - candidates[k] * i, vec);
      for (int j = 0; j < i; j++) {
        vec.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target, tmp);
    return res;
  }
};


#include <iostream>
using namespace std;
void print(vector<vector<int>> res){
    for(auto &vec:res){
        for(auto &i :vec){
            cout << i <<" ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    print(Solution().combinationSum(candidates, target));
    return 0;
}