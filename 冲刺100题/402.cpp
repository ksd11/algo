#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  string removeKdigits(string nums1, int k) {
    string res;
        if(k==0) return res;
        stack<int> st;
        int is_remove = 0;
        int i = 0;
        while(is_remove < k && i<nums1.size()){
            while(is_remove < k && !st.empty() && st.top() > nums1[i]){
                st.pop();
                is_remove++;
            }
            st.push(nums1[i]);
            i++;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(is_remove == k){
            // 将后面剩余元素添加
            res.insert(res.end(), nums1.begin()+i, nums1.end());
        }else{
            // 截断
            res = string(res.begin(), res.begin()+res.size()-(k-is_remove));
        }

    // 移除前导0
    int idx = 0;
    while (idx < res.size() && res[idx] == '0')
      idx++;

    return idx == res.size() ? "0" : res.substr(idx);
  }
};

int main() {
  cout << Solution().removeKdigits("112", 1);
//   cout << Solution().removeKdigits("10", 1);
//   cout << Solution().removeKdigits("1432219", 3);
//   cout << Solution().removeKdigits("52660469", 2);
  return 0;
}