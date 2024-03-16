#include <bits/stdc++.h>
using namespace std;

unsigned long long total_number = 0;

// 获取树状数组中<=x的前缀和
int get(int x, vector<int> &arr) {
  unsigned i = x;
  int res = 0;
  while (i > 0) {
    res += arr[i];
    i -= i & -i;
  }
  return res;
}

void update(int x, vector<int> &arr) {
  unsigned i = x;
  while (i < arr.size()) {
    arr[i] += 1;
    i += i & -i;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }

  vector<int> tr1(n + 1, 0);  // 前面比x大的元素
  vector<int> tr2(n + 1, 0);  // 后面比x小的元素
  vector<int> b(n + 1, 0);

  unsigned long long res = 0;
  for (int i = 0; i < n; i++) {
    int val = get(n, tr1) - get(vec[i], tr1);  // 比val大的元素
    b[i] += val;
    res += val;
    update(vec[i], tr1);
  }

  for (int i = n - 1; i >= 0; i--) {
    int val = get(vec[i]-1, tr2);  // 比val小的元素
    b[i] += val;
    update(vec[i], tr2);
  }

  for (int i = 0; i < n-1; i++) {
    cout << res -  b[i] + i  << " ";
  }
  cout << res - b[n-1] + n-1 << endl;

  return 0;
}