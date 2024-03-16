#include<bits/stdc++.h>
using namespace std;

class Solution {
    unsigned long long total_number = 0;

    void merge(vector<int> &nums, int l1 ,int r1, int l2, int r2){
        vector<int> res(r1-l1+r2-l2);
        int st = min(l1,l2);
        int cnt=0;
        while(l1<r1 && l2<r2){
            if(nums[l1] <= nums[l2]){
                res[cnt++] = nums[l1];
                l1++;
            }else{
                res[cnt++] = nums[l2];
                l2++;
                total_number+=r1-l1;
            }
        }
        while(l1<r1) res[cnt++] = nums[l1++];
        while(l2<r2) res[cnt++] = nums[l2++];
        copy(res.begin(), res.end(), nums.begin()+st);
    }

    void mergeSort(vector<int> &nums, int l, int r){
        if(r-l<=1) return;
        int m = (l+r)>>1;
        mergeSort(nums, l, m);
        mergeSort(nums, m, r);
        merge(nums, l, m, m, r);
    }
public:
    int reversePairs(vector<int>& record) {
        mergeSort(record, 0, record.size());
        return total_number;
    }
};


int main(){
    vector<int> vec = {7,5,6,4};
    cout << Solution().reversePairs(vec);
    return 0;
}