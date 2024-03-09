#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
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
  unordered_map<TreeNode *, int> left_max; // 某个节点往左最大值（包括自身）
  unordered_map<TreeNode *, int> right_max;
  void dfs(TreeNode *root) {
    if (!root)
      return;
    left_max[root] = root->val;
    right_max[root] = root->val;

    if (root->left) {
      dfs(root->left);
      auto tmp = max(left_max[root->left], right_max[root->left]);
      left_max[root] += tmp < 0 ? 0 : tmp;
    }

    if (root->right) {
      dfs(root->right);
      auto tmp = max(right_max[root->right], left_max[root->right]);

      right_max[root] += tmp < 0 ? 0 : tmp;
    }
  }

  int maxPath(TreeNode *root) {
    if (!root)
      return 0;

    int no_include_root = -1e9;
    if (root->left) {
      no_include_root = max(no_include_root, maxPath(root->left));
    }
    if (root->right) {
      no_include_root = max(no_include_root, maxPath(root->right));
    }

    int include_root;
    include_root = left_max[root] + right_max[root] - root->val;
    return max(no_include_root, include_root);
  }

public:
  int maxPathSum(TreeNode *root) {
    if (!root)
      return 0;
    dfs(root);
    return maxPath(root);
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
  //   vector<int> vec = {1, 2, 3};
  //   vector<int> vec = {-3};
  vector<int> vec = {-2, 1};
  auto root = buildTree(vec);
  levelOrder(root);
  cout << Solution().maxPathSum(root) << endl;
}