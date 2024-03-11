#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<pair<int, int>> st;
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
      while (!st.empty() && st.top().first >= heights[i]) st.pop();
      if (st.empty()) {
        left[i] = -1;
      } else {
        left[i] = st.top().second;
      }
      st.push({heights[i], i});
    }

    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top().first >= heights[i]) st.pop();
      if (st.empty()) {
        right[i] = n;
      } else {
        right[i] = st.top().second;
      }
      st.push({heights[i], i});
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, heights[i] * (right[i] - left[i] - 1));
    }
    return res;
  }
};

#include <iostream>
int main() {
  //   vector<int> h = {2, 1, 5, 6, 2, 6};
  vector<int> h = {0, 1, 0, 1};
  //   vector<int> h = {1, 1};
  cout << Solution().largestRectangleArea(h);
  return 0;
}