#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int> &stations, int r, int k) {
        int n = stations.size();
        long sum[n + 1], power[n], diff[n];
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + stations[i]; // 前缀和
        for (int i = 0; i < n; ++i)
            power[i] = sum[min(i + r + 1, n)] - sum[max(i - r, 0)]; // 电量

        auto check = [&](long min_power) -> bool {
            memset(diff, 0, sizeof(diff)); // 重置差分数组
            long sum_d = 0, need = 0;
            for (int i = 0; i < n; ++i) {
                sum_d += diff[i]; // 累加差分值
                long m = min_power - power[i] - sum_d;
                if (m > 0) { // 需要 m 个供电站
                    need += m;
                    if (need > k) return false; // 提前退出这样快一些
                    sum_d += m; // 差分更新
                    if (i + r * 2 + 1 < n) diff[i + r * 2 + 1] -= m; // 差分更新
                }
            }
            return true;
        };

        long left = *min_element(power, power + n), right = left + k + 1; // 开区间写法
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            check(mid) ? left = mid : right = mid;
        }
        return left;
    }
};
