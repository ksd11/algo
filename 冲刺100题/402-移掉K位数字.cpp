#include <bits/stdc++.h>
using namespace std;

// bug version
class Solution {
public:
  string removeKdigits(string num, int k) {
    int remove_cnt = 0;
    string res = num;

    while (remove_cnt < k) {
      // 寻找可以删除的位置
      vector<int> remove_pos;
      for (int i = 0; i < num.size(); i++) {
        if (i + 1 < num.size()) {
          if (num[i] > num[i + 1])
            remove_pos.push_back(i);
        }
      }

      // 元素单调增
      if (remove_pos.size() == 0) {
        res = num.substr(0, res.size() -
                                (k - remove_cnt)); // 删除 k - remove_cnt个元素
        break;
      }

      int st = 0;
      res = "";
      for (int i = 0; i < min(int(remove_pos.size()), k); i++) {
        res += num.substr(st, remove_pos[i] - st);
        st = remove_pos[i] + 1;
        remove_cnt++;
      }
      res += num.substr(st);
      num = res;
    }

    // 删除前导0
    int idx = 0;
    while (idx < res.size() && res[idx] == '0')
      idx++;

    return idx == res.size() ? "0" : res.substr(idx);
  }
};

int main() {
  // cout << Solution().removeKdigits("112", 1);
  cout << Solution().removeKdigits("10", 1);
  return 0;
}