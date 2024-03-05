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
  vector<int> inorderTraversal(TreeNode *root) {
    int top = 0;
    TreeNode *nodes[200];
    TreeNode *node = root;
    vector<int> res;

    if (!node) {
      return res;
    }

    // nodes[top++] = node;

    while (1) {
      while (node->left) {
        nodes[top++] = node;
        node = node->left;
      }

      while (node) {
        // node = nodes[--top];
        // cout << node->value << endl; // 二次出栈
        res.push_back(node->val);

        if (node->right) {
          node = node->right;
          break;
        } else if (top) {
          --top;
          node = nodes[top];
        } else {
          return res;
        }
      }
    }
  }
};