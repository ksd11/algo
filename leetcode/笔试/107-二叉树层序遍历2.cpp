/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    stack<pair<int, int>> st; // value  level
    unordered_map<TreeNode*, int> level_map;

    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    st.push({root->val,0});
    level_map[root] = 0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->right != nullptr){
            q.push(node->right);
            st.push({node->right->val, level_map[node]+1});
            level_map[node->right] = level_map[node]+1;
        }
        if(node->left != nullptr){
            q.push(node->left);
            st.push({node->left->val, level_map[node]+1});
            level_map[node->left] = level_map[node]+1;
        }
    }

    int last_level = -1;
    int cnt = -1;
    while(!st.empty()){
        auto pl = st.top();
        st.pop();
        if(pl.second != last_level){
            last_level = pl.second;
            cnt++;
            res.push_back({});
        }
        res[cnt].push_back(pl.first);
    }
    return res;
  }
};