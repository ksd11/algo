#include <bits/stdc++.h>
using namespace std;

const int LEN = 1e4 + 10;

// https://blog.csdn.net/dark_cy/article/details/88698736
// 计算子串的next

class Solution {
  void Getnext(int next[], string t) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length() - 1) {
      if (k == -1 || t[j] == t[k]) {
        j++;
        k++;
        if (t[j] == t[k]) // 当两个字符相同时，就跳过
          next[j] = next[k];
        else
          next[j] = k;
      } else
        k = next[k];
    }
  }

  int KMP(string s, string t) {
    int i = 0, j = 0;
    int next[LEN];
    Getnext(next, t);
    while (i < int(s.length()) && j < int(t.length())) {
      if (j == -1 || s[i] == t[j]) {
        i++;
        j++;
      } else
        j = next[j]; // j回退。。。
    }
    if (j >= t.length())
      return (i - t.length()); // 匹配成功，返回子串的位置
    else
      return (-1); // 没找到
  }

public:
  int strStr(string haystack, string needle) { return KMP(haystack, needle); }
};

int main() {
  cout << Solution().strStr("hello", "ll");
  return 0;
}
