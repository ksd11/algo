#include <vector>
using namespace std;

// 空间复杂度O(n)
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> nums_ = nums;
//         k = k%nums.size();
//         for(int i=0;i<nums.size();i++){
//             nums[i] = nums_[(i-k+nums.size())%nums.size()];
//         }

//     }
// };

class Solution {
public:

    int gcd(int m, int n){
        while(m != 0){
            int temp = m;
            m = n%m;
            n = temp;
        }
        return n;
    }

    void rotate(vector<int>& nums, int k) {
        vector<int> nums_ = nums;
        k = k%nums.size();
        if(k==0){
            return;
        }

        int g = gcd(nums.size(), k);

        if(g != 1){
            for(int i=0;i<g;i++){ // 一共有g组
                int j = i;
                int temp = nums[j];
                do{
                    int next = (j+k)%nums.size();
                    int temp_ = nums[next];
                    nums[next] = temp;
                    temp = temp_;
                    j = next;
                }while(j!=i);
            }
        }else{
            int i = 0;
            int j = i;
            int temp = nums[j];
            do{
                int next = (j+k)%nums.size();
                int temp_ = nums[next];
                nums[next] = temp;
                temp = temp_;
                j = next;
            }while(j!=i);
        }
    }
};