

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
    bool is_two_tree_symmetric(TreeNode* t1, TreeNode* t2){
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val != t2->val) return false;
            return is_two_tree_symmetric(t1->left, t2->right) && is_two_tree_symmetric(t1->right, t2->left);
        }

        return t1==t2;
    }

public:
    bool isSymmetric(TreeNode* root) {
        auto left = root->left;
        auto right = root->right;
        return is_two_tree_symmetric(left, right);
    }
};