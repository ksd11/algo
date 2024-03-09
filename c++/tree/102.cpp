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
#include <queue>
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
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> vecs;
    if (root == nullptr) {
      return vecs;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      queue<TreeNode *> new_q;
      vector<int> vec;

      while (!q.empty()) {
        auto node = q.front();
        q.pop();
        vec.push_back(node->val);
        if(node->left){
            new_q.push(node->left);
        }
        if(node->right){
            new_q.push(node->right);
        }
      }

      vecs.push_back(std::move(vec));
      q = std::move(new_q);
    }
    return vecs;
  }
};