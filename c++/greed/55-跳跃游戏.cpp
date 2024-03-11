#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> is_visited(n, false);
    queue<int> q;
    q.push(0);
    is_visited[0] = true;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (int i = 1; i <= nums[v]; i++) {
        if (v + i < n) {
          if(!is_visited[v + i])
            q.push(v + i);
          is_visited[v + i] = true;
        }
      }
    }
    return is_visited[n - 1];
  }
};

int main() {
  vector<int> nums = {2, 5, 0, 0};
  Solution().canJump(nums);
  return 0;
}