
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

    TreeNode* predorder(TreeNode *root){
        if(root == nullptr) return nullptr;

        auto right = root->right; // 临时保存
        if(root->left){
            root->right = predorder(root->left);
            root->left = nullptr;
            auto p = root->right;
            while(p->right){
                p = p->right;
            }
            p->right = predorder(right);
        }else{
            root->right = predorder(right);
        }
        return root;
    }

public:
  void flatten(TreeNode *root) {
    predorder(root);
  }
};