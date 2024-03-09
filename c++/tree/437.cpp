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
    unsigned long long cnt = 0;

    void sum(TreeNode *root, long long targetSum){
        if(root == nullptr) return;
        if(targetSum - root->val == 0) cnt++;
        sum(root->left, targetSum - root->val);
        sum(root->right, targetSum - root->val);
    }

    void preorder(TreeNode* root, long long  targetSum){
        if(root == nullptr) return;
        sum(root, targetSum);
        preorder(root->left, targetSum);
        preorder(root->right, targetSum);
    }
  

public:
  int pathSum(TreeNode *root, int targetSum) {
    preorder(root, targetSum);
    return cnt;
  }
};

const int NAN = 2000;
TreeNode *buildTree(vector<int> &vec) {
  TreeNode *root = nullptr;
  queue<TreeNode *> q;

  if (vec.size() == 0)
    return nullptr;

  int cnt = 0;
  root = new TreeNode(vec[cnt++]);
  q.push(root);

  while (cnt < vec.size()) {

    auto node = q.front();
    q.pop();

    auto left_val = vec[cnt++];
    if (left_val == NAN) {
      node->left = nullptr;
    } else {
      node->left = new TreeNode(left_val);
      q.push(node->left);
    }

    if (cnt < vec.size()) {
      auto right_val = vec[cnt++];
      if (right_val == NAN) {
        node->right = nullptr;
      } else {
        node->right = new TreeNode(right_val);
        q.push(node->right);
      }
    }
  }
  return root;
}

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
      if (node->left) {
        new_q.push(node->left);
      }
      if (node->right) {
        new_q.push(node->right);
      }
    }

    vecs.push_back(std::move(vec));
    q = std::move(new_q);
  }

  for (auto &vec : vecs) {
    for (auto &ele : vec) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return vecs;
}

int main() {
  //   vector<int> vec = {10, 5, -3, 3, 2, NAN, 11, 3, -2, NAN, 1};
  vector<int> vec = {1, 2, 3, 1};
  auto root = buildTree(vec);
  levelOrder(root);
  cout << Solution().pathSum(root, 3) << endl;
}