#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if (r - l <= 1)
            return;
        int base = nums[l];
        int i = l + 1;
        int j = r - 1;
        while (i <= j) {
            while (i <= j && nums[i] < base)
                i++;
            while (i <= j && nums[j] >= base)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        quickSort(nums, l, j);
        quickSort(nums, j + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> res = nums;
        srand ( unsigned ( time(0) ) );
        random_shuffle(res.begin(), res.end());
        quickSort(res, 0, res.size());
        return res;
    }
};