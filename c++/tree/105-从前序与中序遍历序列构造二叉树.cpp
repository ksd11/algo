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

#include <vector>
#include <algorithm>
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

    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2){

        if(r1<=l1) return nullptr;

        if(r1-l1 == 1){
            return new TreeNode(preorder[l1]);
        }

        int ele = preorder[l1];
        int index = std::find(inorder.begin()+l2, inorder.begin()+r2, ele)- inorder.begin()-l2;
        
        auto root = new TreeNode(ele);
        
        root -> left = buildTreeHelper(preorder, inorder, l1+1, l1+index+1, l2, l2+index);

        root -> right = buildTreeHelper(preorder, inorder, l1+index+1, r1, l2+index+1, r2);
        return root;
    }
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

    return buildTreeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};

int main(){
    vector<int> predorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution().buildTree(predorder, inorder);

    return 0;
}