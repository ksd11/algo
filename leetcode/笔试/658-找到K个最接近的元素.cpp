#include <bits/stdc++.h>
using namespace std;

class Solution {

    // 在排序数组中找到第一个大于等于x的数
    int search(vector<int> &arr, int x){
        int l = 0;
        int r = arr.size()-1;
        int ans = arr.size();
        while(l<=r){
            int m = (l+r) >> 1;
            if(arr[m] == x) return m;
            else if(arr[m] >= x){
                r = m-1;
                ans = m;
            } 
            else l = m+1;
        }
        return ans;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = search(arr, x);
        int l = idx-1;
        int r = idx;
        int n = arr.size();
        vector<int> res;
        while(l>=0 && r < n && res.size()<k){
            if(x - arr[l] <= arr[r]-x){
                res.push_back(arr[l]);
                l--;
            }else{
                res.push_back(arr[r]);
                r++;
            }
        }
        while(l >= 0 && res.size()<k){
            res.push_back(arr[l]);
            l--;
        }

        while(r < n && res.size()<k){
            res.push_back(arr[r]);
            r++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};