struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <algorithm>
class Solution {
public:
  // 返回最小值和最大值
  bool isValidBSTHelper(TreeNode *root, int *min_val, int *max_val) {
    if (root == nullptr)
      return true;
    if (root->left == nullptr && root->right == nullptr) {
      if (min_val)
        *min_val = root->val;
      if (max_val)
        *max_val = root->val;
      return true;
    }

    if (root->left != nullptr && root->left->val >= root->val)
      return false;

    if (root->right != nullptr && root->right->val <= root->val)
      return false;

    int l_min = ~(1<<31), l_max = 1<<31 , r_min = ~(1<<31), r_max = 1<<31;
    bool success = isValidBSTHelper(root->left, &l_min, &l_max) && isValidBSTHelper(root->right, &r_min, &r_max);
    if(!success) return false;

    if((l_max != 1<<31 && l_max >= root->val) || (r_min != ~(1<<31) && r_min <= root->val)){
        return false;
    }

    if(min_val){
        *min_val = std::min(l_min, root->val);
    }
    if(max_val){
        *max_val = std::max(r_max, root->val);
    }
    return true;
  }

  bool isValidBST(TreeNode *root) {
    
    return isValidBSTHelper(root, nullptr, nullptr);
  }
};

#include <iostream>
using namespace std;

int main() {
  TreeNode n4 = {-60};
  TreeNode n2 = {-4, &n4, nullptr};
  TreeNode root = {22, &n2, nullptr};

  cout << Solution().isValidBST(&root) << endl;
  return 0;
}