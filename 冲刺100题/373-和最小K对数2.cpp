#include<bits/stdc++.h>
using namespace std;

/*
[1,7,11], [2,4,6]

初始堆有k个元素，假设k=2
=> 1 + 2, 7 + 2

每次从堆里取出一个元素，设元素下标为(i,j)，那么
将 (i, j+1)加入堆

*/


struct Node{
    int val;
    int x,y;
    bool operator>(const Node& b) const{
        return val > b.val;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        for(int i=0;i<min(k, int(nums1.size()));i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        while(k--){
            Node node = pq.top();
            pq.pop();
            res.push_back({nums1[node.x], nums2[node.y]});
            if(node.y + 1 < nums2.size()){
                pq.push({nums1[node.x]+nums2[node.y+1], node.x, node.y+1});
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {1,2,4,5,6};
    vector<int> nums2 = {3,5,7,9};
    Solution().kSmallestPairs(nums1, nums2, 20);
    return 0;
}