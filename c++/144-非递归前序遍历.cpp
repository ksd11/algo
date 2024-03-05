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

#include<iostream>
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root){
        return res;
    }

    TreeNode* node = root;
    int top = 0;
    TreeNode *nodes[200];

    res.push_back(node->val);

    while(1){
        while(node->left){
            nodes[top++] = node;
            node = node->left;
            res.push_back(node->val);
        }

        while(node){
            if(node->right){
                node = node->right;
                res.push_back(node->val);
                break;
            }else if(top){
                node = nodes[--top];
            }else{
                return res;
            }
        }
    }

    return res;

  }
};