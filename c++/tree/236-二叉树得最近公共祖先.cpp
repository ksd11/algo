
#include <vector>
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
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    vector<TreeNode*> cur;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || (!path1.empty() && !path2.empty())) return;

        cur.push_back(root);

        if(root == p) path1 = cur;
        if(root == q) path2 = cur;

        dfs(root->left,p,q);
        dfs(root->right,p,q);
        cur.pop_back();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q); 
        int i=0,j=0;
        while(i<path1.size()  && j<path2.size() && path1[i] == path2[j]){
            i++;
            j++;
        }
        return path1[i-1];
    }
};