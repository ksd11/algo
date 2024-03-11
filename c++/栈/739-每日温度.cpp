#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<pair<int, int>> st;
    int cnt = 0;
    vector<int> res(temperatures.size());
    for (auto &i : res) i = 0;
    for (auto &i : temperatures) {
      while (!st.empty() && st.top().first < i) {
        res[st.top().second] = cnt - st.top().second;
        st.pop();
      }
      st.push({i, cnt});
      cnt++;
    }
    return res;
  }
};