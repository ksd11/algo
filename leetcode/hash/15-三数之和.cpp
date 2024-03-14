#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const
    {
        size_t h1 = hash<T1>()(pair.first); //用默认的 hash 处理 pair 中的第一个数据 X1
        size_t h2 = hash<T2>()(pair.second);//用默认的 hash 处理 pair 中的第二个数据 X2
        return (h1 >> 17) ^ (h2 << 15);
    }
};

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, unordered_set<int>> num_pos;
    unordered_set<pair<int, int>, pair_hash> couple;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        num_pos[nums[i]].insert(i);
    }

    vector<vector<int>> res;
    unordered_set<int> visited;
    if(nums[0] > 0) return res;
    for(int i=0;i<n;i++){
        if(visited.count(nums[i])) continue;
        visited.insert(nums[i]);
        if(nums[i] > 0) return res;
        
        for(int j=i+1;j<n;j++){
            if(couple.count({nums[i],nums[j]})) continue;
            couple.insert({nums[i],nums[j]});

            int sum = nums[i] + nums[j];
            if(num_pos[-sum].size() > int(nums[i] == -sum) + int(nums[j] == -sum)){
                res.push_back({nums[i], nums[j], -sum});
                couple.insert({nums[i], -sum});
                couple.insert({nums[j], -sum});
            }

        }
    }
    return res;
  }
};

void print2D(vector<vector<int>> res) {
  for (auto &vec : res) {
    for (auto &i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    // vector<int> vec ={0,0,0};
    print2D(Solution().threeSum(vec));
    return 0;
}