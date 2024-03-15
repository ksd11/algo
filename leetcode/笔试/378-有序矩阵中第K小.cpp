#include<vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> index(matrix.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
        int n = matrix.size();

        for(int i=0;i<n;i++) {
            pq.push({matrix[i][0], i});
        }

        int cnt = 0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            // 添加新元素s
            index[p.second]++;
            if(index[p.second] < n) pq.push({matrix[p.second][index[p.second]], p.second});
            cnt++;
            if(cnt == k) return p.first;
        }
        return -1;
    }
};