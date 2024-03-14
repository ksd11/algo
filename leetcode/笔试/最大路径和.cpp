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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <unordered_map>
using namespace std;

class Solution {
    void buildHeightMap(unordered_map<TreeNode*, pair<int, int>> &high_map, TreeNode* root){
        if(!root) return;
        buildHeightMap(high_map, root->left);
        buildHeightMap(high_map, root->right);
        int max_left=root->val, max_right=root->val;
        if(root->left)
            max_left = max(0 , max(high_map[root->left].first, high_map[root->left].second))+root->val;
        if(root->right)
            max_right = max(0, max(high_map[root->right].first, high_map[root->right].second))+root->val;
        high_map[root] = {max_left, max_right};
    }

    int getMaxPath(unordered_map<TreeNode*, pair<int, int>> &high_map, TreeNode *root){
        if(!root) return 0;
        int res = high_map[root].first+high_map[root].second - root->val;
        if(root->left) res = max(res, getMaxPath(high_map, root->left));
        if(root->right) res = max(res, getMaxPath(high_map, root->right));
        return res;
    }
 public:
  int maxPathSum(TreeNode *root) {
    unordered_map<TreeNode*, pair<int, int>> high_map;
    buildHeightMap(high_map, root);
    return getMaxPath(high_map, root);
  }
};