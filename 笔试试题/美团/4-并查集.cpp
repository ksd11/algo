#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
const int N = 1E5 + 10;
unordered_map<int, int> p;
int n, m, q;
map<pair<int, int>, bool> mp;
vector<vector<int>> op; // 不要放到栈里！

// 一直往上找，知道找到根
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void union_(int a, int b) {
  int pa = find(a), pb = find(b);
  p[pa] = pb;
}

int main() {
  cin >> n >> m >> q;
  // 朋友关系
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    p[a] = a;
    p[b] = b;
    if (a > b) swap(a, b);
    mp.insert({{a, b}, true});
  }

  op.resize(q);
  // 查询 or 删除
  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int o, a, b;
    cin >> o >> a >> b;
    if (a > b) swap(a, b);
    if (o == 1 && (!mp.count({a, b}) || mp[{a, b}] == false)) continue;
    op[cnt++] = {o, a, b};
    if (o == 1 && mp.count({a, b})) {
      mp[{a, b}] = false;
    }
  }

  for (auto &i : mp) {
    if (i.second) union_(i.first.first, i.first.second);
  }

  stack<string> res;
  for (int i = cnt - 1; i >= 0; i--) {
    int id = op[i][0];
    int a = op[i][1];
    int b = op[i][2];

    int fa = find(a);
    int fb = find(b);

    if (id == 1) {
      union_(a, b);
    } else {
      if (fa && find(a) == find(b))
        res.push("Yes");
      else
        res.push("No");
    }
  }
  while (res.size()) {
    cout << res.top() << endl;
    res.pop();
  }
  return 0;
}