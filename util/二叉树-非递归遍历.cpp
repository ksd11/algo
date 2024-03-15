#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) { val = v; }
};

vector<int> Mytemplate(TreeNode *root) {
  vector<int> res;
  if (!root)
    return res;
  stack<TreeNode *> st;
  //   res.push_back(root->val);
  st.push(root);
  TreeNode *p = root;
  while (!st.empty()) {
    while (p->left) {
      p = p->left;
      st.push(p);
      //   res.push_back(p->val);
    }
    // 此时p无左孩子
    while (!st.empty()) {
      p = st.top();
      st.pop();
      // 此时可遍历p
      if (p->right) {
        p = p->right;
        st.push(p);
        // res.push_back(p->val);
        break;
      }
    }
  }
  return res;
}

vector<int> preorder(TreeNode *root) {
  vector<int> res;
  if (!root)
    return res;
  stack<TreeNode *> st;
  res.push_back(root->val);
  st.push(root);
  TreeNode *p = root;
  while (!st.empty()) {
    while (p->left) {
      p = p->left;
      st.push(p);
      res.push_back(p->val);
    }
    // 此时p无左孩子
    while (!st.empty()) {
      p = st.top();
      st.pop();
      // 此时可遍历p
      if (p->right) {
        p = p->right;
        st.push(p);
        res.push_back(p->val);
        break;
      }
    }
  }
  return res;
}

vector<int> inorder(TreeNode *root) {
  vector<int> res;
  if (!root)
    return res;
  stack<TreeNode *> st;
  st.push(root);
  TreeNode *p = root;
  while (!st.empty()) {
    while (p->left) {
      p = p->left;
      st.push(p);
    }
    // 此时p无左孩子
    while (!st.empty()) {
      p = st.top();
      st.pop();
      res.push_back(p->val);
      // 此时可遍历p
      if (p->right) {
        p = p->right;
        st.push(p);
        break;
      }
    }
  }
  return res;
}

vector<int> postorder(TreeNode *root) {
  vector<int> res;
  if (!root)
    return res;
  stack<TreeNode *> st;
  res.push_back(root->val);
  st.push(root);
  TreeNode *p = root;
  while (!st.empty()) {
    while (p->right) {
      p = p->right;
      st.push(p);
      res.push_back(p->val);
    }
    // 此时p无左孩子
    while (!st.empty()) {
      p = st.top();
      st.pop();
      // 此时可遍历p
      if (p->left) {
        p = p->left;
        st.push(p);
        res.push_back(p->val);
        break;
      }
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

const int MYNULL = 2000;
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

void print1D(vector<int> res) {
  for (auto &i : res) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec = {3, 1, 2};
  auto root = buildTree(vec);
  print1D(inorder(root));
}