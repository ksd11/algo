#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // unordered_map<int, vector<pair<int, int>>> mp1;
        // unordered_map<int, vector<pair<int, int>>> mp2;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val1 = nums1[i]+nums2[j];
                int val2 = nums3[i]+nums4[j];
                // if(mp.count(val)) 
                mp1[val1]+=1;
                mp2[val2]+=1;
            }
        }

        int res = 0;
        for(auto& kv:mp1){
            int v = kv.first;
            if(mp2.count(-v)){
                res += kv.second * mp2[-v];
            }

        }  
        return res;     
    }
};