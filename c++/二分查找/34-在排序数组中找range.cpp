#include <vector>
using namespace std;

class Solution {
  // 找一个刚好小于target的数
  int searchLess(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] >= target)
        r = mid - 1;  // 保证>r的位置不可能取
      else
        l = mid + 1;
    }
    if (r != -1 && nums[r] >= target)
      return r - 1;
    else
      return r;
  }

  // 找一个刚好大于target的数
  int searchGreat(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] <= target)
        l = mid + 1;  // 保证<l的位置不能取
      else
        r = mid - 1;
    }
    if (nums[l] <= target) return l + 1;
    return l;
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    if (nums.size() == 0) return res;
    int l = searchLess(nums, target);
    int r = searchGreat(nums, target);

    if (l == nums.size() - 1 || r == 0)
      return res;  // 找不到比其小，也找不到比其大

    if (nums[l + 1] != target || nums[r - 1] != target) return res;

    res.clear();
    res.push_back(l + 1);
    res.push_back(r - 1);

    return res;
  }
};

#include <iostream>
void print1D(vector<int> res) {
  for (auto& i : res) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 3,  4,
                      4, 4, 4, 5, 5, 6, 6, 6, 8, 10, 10};
  // vector<int> nums = {5,7,7,8,8,10};
  print1D(Solution().searchRange(nums, 4));
  return 0;
}