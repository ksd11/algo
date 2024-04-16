#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int n = edges.size(), time[n], ans = -1;
        memset(time, 0, sizeof(time));


        for (int i = 0, clock = 1; i < n; ++i) {
            // 已经访问过了？
            if (time[i]) continue;

            for (int x = i, start_time = clock; x >= 0; x = edges[x]) {
                if (time[x]) { // 重复访问
                    if (time[x] >= start_time) // 找到了一个新的环
                        ans = max(ans, clock - time[x]);
                    break;
                }
                time[x] = clock++;
            }
        }
        return ans;
    }
};

int main(){

    // vector<int> vec = {-1,4,-1,2,0,4};
    vector<int> vec = {3,3,4,2,3};
    cout << Solution().longestCycle(vec);
    return 0;
}
