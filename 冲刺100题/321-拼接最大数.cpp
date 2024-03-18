#include<bits/stdc++.h>
using namespace std;


void print1D(vector<int> res) {
  for (auto &i : res) {
    cout << i << " ";
  }
  cout << endl;
}

bool Compare (const vector<int> &v1, const vector<int> &v2){
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0, j = 0;
    while(i<n1 && j<n2){
        if(v1[i] != v2[i]) return v1[i] < v2[i];
        i++;
        j++;
    }
    if(i==n1 && j==n2) return 0;
    return i<n1 ? 1 : -1;
}

bool MyGreat (const vector<int> &v1, const vector<int> &v2, int i1, int i2){
    int n1 = v1.size();
    int n2 = v2.size();
    int i = i1, j = i2;
    while(i<n1 && j<n2){
        if(v1.at(i) != v2.at(j)) return v1.at(i) > v2.at(j);
        i++;
        j++;
    }
    return i<n1 ? true : false;
}


class Solution {

    // 从nums1中取出m个数，使得结果最大
    vector<int> get_max(vector<int> &nums1, int m){
        vector<int> res;
        if(m==0) return res;
        stack<int> st;
        int is_remove = 0;
        int i = 0;
        int k = nums1.size()-m;
        while(is_remove < k && i<nums1.size()){
            while(is_remove < k && !st.empty() && st.top() < nums1[i]){
                st.pop();
                is_remove++;
            }
            st.push(nums1[i]);
            i++;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(is_remove == k){
            // 将后面剩余元素添加
            res.insert(res.end(), nums1.begin()+i, nums1.end());
        }else{
            // 截断
            res = vector<int>(res.begin(), res.begin()+m);
        }
        return res;
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
        vector<int> res;
        int i = 0, j= 0;
        while(i<nums1.size() && j<nums2.size()){
            if(MyGreat(nums1, nums2, i, j) > 0){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()) res.push_back(nums1[i++]);
        while(j<nums2.size()) res.push_back(nums2[j++]);
        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(k,-1);
        for(int i=0;i<=k;i++){
            int j = k-i;
            if(i > m || j < 0 || j>n) continue;
            auto v1 = get_max(nums1, i);
            auto v2 = get_max(nums2, j);
            auto v3 = merge(v1, v2);
            res = max(res ,v3, Compare);
            // if(res < v3){
            //     res = v3;
            //     print1D(v1);
            //     print1D(v2);
            //     cout << endl;
            // }
        }
        return res;
    }
};


int main(){

    // vector<int> v1 = {3,4,6,5};
    // vector<int> v2 = {9,1,2,5,8,3};
    // int k = 5;
    // vector<int> v1 = {2,5,6,4,4,0};
    // vector<int> v2 = {7,3,8,0,6,5,7,6,2};
    // int k = 15;
    vector<int> v1 = {8,6,9};
    vector<int> v2 = {1,7,5};
    int k = 3;
    print1D(Solution().maxNumber(v1, v2, k));

    return 0;
}