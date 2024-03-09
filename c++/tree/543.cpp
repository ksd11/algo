
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
#include <iostream>
using namespace std;

class Solution {
public:
  int ans = 0;

  int max_height(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int L = 0, R = 0;
    if (root->left != nullptr) {

      L = max_height(root->left) + 1;
    }

    if (root->right != nullptr) {

      R = max_height(root->right) + 1;
    }

    ans = std::max(L + R, ans);
    return max(L, R);
  }

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    max_height(root);
    return ans;
  }
};

int main() {
  TreeNode n4 = {4};
  TreeNode n5 = {5};
  TreeNode n3 = {3};
  TreeNode n2 = {2, &n4, &n5};
  TreeNode root = {1, &n2, &n3};

  cout << Solution().diameterOfBinaryTree(&root) << endl;
  return 0;
}