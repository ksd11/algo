#include <iostream>
#include <vector>
using namespace std;

class Solution {
  vector<vector<string>> save[20]; // 从i开始的所有回文组合

  bool check(string s, int st, int ed) {
    while (st < ed) {
      if (s[st] != s[ed - 1])
        return false;
      st++;
      ed--;
    }
    return true;
  }

  vector<vector<string>> dfs(string s, int k) {

    vector<vector<string>> res;
    if (save[k].size() != 0)
      return save[k];
    if (k == s.size())
      return res;

    int size = s.size();
    string substr;
    for (int i = k; i < size; i++) {
      if (!check(s, k, i + 1)) {
        continue;
      }
      substr = s.substr(k, i - k + 1);
      auto subarr = dfs(s, i + 1);
      vector<string> vec;
      vec.push_back(substr);

      if (subarr.size() != 0) {
        for (auto &arr : subarr) {
          auto tmp = vec;
          tmp.insert(tmp.end(), arr.begin(), arr.end());
          res.push_back(tmp);
        }
      } else {
        res.push_back(vec);
      }
    }
    return save[k] = res;
  }

public:
  vector<vector<string>> partition(string s) { return dfs(s, 0); }
};

void print2D(vector<vector<string>> res) {
  for (auto &vec : res) {
    for (auto &i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  print2D(Solution().partition("cdd"));
  return 0;
}