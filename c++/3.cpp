#include <iostream>
using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
};

// 二叉树中序遍历 非递归
void inorder(TreeNode *node) {
  if (!node) {
    return;
  }
  inorder(node->left);
  cout << node->value << endl;
  inorder(node->right);
}

void inorder2(TreeNode *node) {
  int top = 0;
  TreeNode *nodes[200];

  if (!node) {
    return;
  }

  // nodes[top++] = node;

  while (1) {
    while (node->left) {
      nodes[top++] = node;
      node = node->left;
    }

    while (node) {
      // node = nodes[--top];
      cout << node->value << endl; // 二次出栈

      if (node->right) {
        node = node->right;
        break;
      } else if (top) {
        --top;
        node = nodes[top];
      } else {
        return;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  TreeNode l = {1, NULL, NULL};
  TreeNode r = {5, NULL, NULL};
  TreeNode root = {4, &l, &r};

  inorder2(&root);
  return 0;
}