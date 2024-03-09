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
    int cnt;
    bool success;
    int val;

    void predorder(TreeNode* root){
        if(root == nullptr || success) return;
        
        predorder(root->left);

        if(success) return;

        if(--cnt == 0){
            // 找到元素
            val = root->val;
            return;
        }
        predorder(root->right);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        success = false;
        predorder(root);
        return val;
    }
};