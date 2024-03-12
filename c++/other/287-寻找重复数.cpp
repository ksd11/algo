#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        fast = forward(nums, fast, 2);
        slow = forward(nums, slow, 1);
        //题意说明肯定是有环的
        while(fast != slow){
            fast = forward(nums, fast, 2);
            slow = forward(nums, slow, 1);
        }

        slow = 0;
        while(fast != slow){
            fast = forward(nums, fast, 1);
            slow = forward(nums, slow, 1);
        }
        return slow;
    }

    int forward(vector<int> & nums, int pos, int n){
        if(pos == -1) return -1;
        while(pos < nums.size() && n--){
            pos = nums[pos];
        }
        return pos<nums.size() ? pos:-1;
    }

};

int main(){
    // vector<int> vec = {2,5,9,6,9,3,8,9,7,1};
    vector<int> vec = {1,3,4,2,2};
    Solution().findDuplicate(vec);
    return 0;
}