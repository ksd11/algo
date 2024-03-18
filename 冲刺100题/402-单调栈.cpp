#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    int remove_cnt = 0;
    int i = 0;
    while(remove_cnt < k && i<num.size()){
        if(st.empty() || num[i] >= st.top()) st.push(num[i]);
        else{
            while(!st.empty() && num[i] < st.top()){
                remove_cnt++;
                st.pop();
                if(remove_cnt >= k) break;
            }
            if(remove_cnt >= k) break;
            st.push(num[i]);
        }
        i++;
    }

    //拼装栈 + i~end
    string res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    res += num.substr(i);

    // 判断是否移除的元素较少
    if(remove_cnt < k){
        res = res.substr(0, res.size()-(k-remove_cnt));
    }

    // 移除前导0
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