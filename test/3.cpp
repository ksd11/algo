#include <bits/stdc++.h>
using namespace std;

bool Compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}

int main() {
  const int MOD = 1e9 + 7;
  int n, q;
  cin >> n >> q;

  vector<unsigned long long> res(n);
  vector<int> exclude_arr(n);  // 排除的次数矩阵
  unsigned long long total_sum = 0;
  unsigned long long total_sum_mod = 0;

  for (int i = 0; i < n; i++) {
    cin >> res[i];
    total_sum += res[i];
  }
  total_sum_mod = total_sum % MOD;

  int max_exclude_cnt = 0;
  for (int i = 0; i < q; i++) {
    int exclude;
    cin >> exclude;
    exclude_arr[exclude - 1]++;

    // 得到被排除最多次的
    max_exclude_cnt = max(max_exclude_cnt, exclude_arr[exclude]);
  }

  // 下标，次数
  vector<pair<int, int>> cnt_arr(n);
  for (int i = 0; i < n; i++) {
    cnt_arr[i] = {i, q - exclude_arr[i]};
  }

  sort(cnt_arr.begin(), cnt_arr.end(), Compare);

  int idx = 0;
    vector<unsigned long long> base(q+1,0);
    base[0] = 1;
    unsigned long long b = 1;
    for(int i=1;i<=q;i++){
        b = b << 1;
        b %= MOD;
        base[i] = b;
    }

  unsigned long long res_sum = 0;
    int k = n-1;
    while(k >= 0){
        int cnt;
        if(k!=0) cnt = cnt_arr[k].second-cnt_arr[k-1].second;
        else cnt = cnt_arr[0].second;
        auto ele = res[cnt_arr[k].first];
        res_sum = (res_sum+ele) * base[cnt];
        res_sum %= MOD;
        k--;
    }

  cout << res_sum << endl;

  return 0;
}