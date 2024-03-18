#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    int remove_cnt = 0;
    string res = num;
    set<int> delete_pos;

    for (int i = 0; i < num.size(); i++) {
      if (i + 1 < num.size()) {
        if (num[i] > num[i + 1]) {
          delete_pos.insert(i);
          if(delete_pos.size() >= k) break;
          int j = i - 1;
          while (j >= 0 && num[j] > num[i + 1]) {
            delete_pos.insert(j);
            if(delete_pos.size() >= k) break;
            j--;
          }
        }
        
      }
    }

    int l = 0;
    for (int i = 0; i < num.size(); i++) {
      if (remove_cnt >= k || delete_pos.count(i) == 0) {
        swap(num[i], num[l]);
        l++;
      } else {
        remove_cnt++;
      }
    }

    res = num.substr(0, l);

    // 元素单调增
    if (remove_cnt < k) {
      res = res.substr(0, res.size() -
                              (k - remove_cnt)); // 删除 k - remove_cnt个元素
    }

    // 删除前导0
    int idx = 0;
    while (idx < res.size() && res[idx] == '0')
      idx++;

    return idx == res.size() ? "0" : res.substr(idx);
  }
};

int main() {
//   cout << Solution().removeKdigits("112", 1);
//   cout << Solution().removeKdigits("10", 1);
//   cout << Solution().removeKdigits("1432219", 3);
  cout << Solution().removeKdigits("52660469", 2);
  return 0;
}