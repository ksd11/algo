#include <algorithm>
#include <vector>
using namespace std;

// 超时O(nk)
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    const int INF = 1e4 + 5;
    vector<int> max_val(nums.size(), -INF);  // 初始化数组大小
    vector<int> res;
    int cnt = 1;
    int idx = 0;
    for (auto& num : nums) {
      if (cnt < k) {
        for (int j = 0; j < cnt; j++) {
          max_val[(idx + j) % k] = max(max_val[(idx + j) % k], num);
        }
      }

      else {
        // for (int j = 0; j < k; j++) {
        //   max_val[(idx + j) % k] = max(max_val[(idx + j) % k], num);
        // }
        if(max_val[idx] < num){
            max_val[idx] = num;
        }else{
            max_val[(idx+1) % k] = num;
        }
        res.push_back(max_val[idx]);
        max_val[idx] = -INF;
        idx = (idx + 1) % k;
      }
      cnt++;
    }
    return res;
  }
};

int main() {
  vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
  Solution().maxSlidingWindow(vec, 3);
  return 0;
}