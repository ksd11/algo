#include <algorithm>
#include <iostream>
#include <queue>
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
  
    int result = -1000+5;

    // 单条路径最大值
    int maxPath(TreeNode* root){
        if(!root) return 0;

        int res = root->val;
        int left = max(maxPath(root->left), 0); // 单条路径最大值
        int right = max(maxPath(root-> right), 0);

        result = max(result, res+left+right);
        return res + max(left, right);       

    }

public:
  int maxPathSum(TreeNode *root) {
    if (!root) return 0;
    maxPath(root);
    return result;
  }
};