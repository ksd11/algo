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

#include <algorithm>
#include <iostream>
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }

    TreeNode *node = root;
    int top = 0;
    TreeNode *nodes[200];

    res.push_back(node->val);

    while (1) {
      while (node->right) {
        nodes[top++] = node;
        node = node->right;
        res.push_back(node->val);
      }

      while (node) {
        if (node->left) {
          node = node->left;
          res.push_back(node->val);
          break;
        } else if (top) {
          node = nodes[--top];
        } else {
          reverse(res.begin(), res.end());
          return res;
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode l = {1, NULL, NULL};
  TreeNode r = {5, NULL, NULL};
  TreeNode root = {4, &l, &r};

//   Solution().postorderTraversal(&root);

    for (auto &i : Solution().postorderTraversal(&root)) {
      cout << i << endl;
    }
  return 0;
}