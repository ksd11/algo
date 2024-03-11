#include <set>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> q;
    set<char> left = {'(', '{', '['};
    set<char> right = {')', '}', ']'};
    for (auto& c : s) {
      if (left.count(c))
        q.push(c);
      else {
        if (q.empty()) return false;
        auto cc = q.top();
        q.pop();
        if (cc == '(' && c == ')' || cc == '{' && c == '}' ||
            cc == '[' && c == ']') {
          continue;
        }
        return false;
      }
    }
    if (!q.empty()) return false;
    return true;
  }
};