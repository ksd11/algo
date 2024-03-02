from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node, total):
            if node is None:
                return total
            total = dfs(node.right, total)
            total += node.val
            node.val = total
            total = dfs(node.left, total)
            return total
        dfs(root, 0)
        return root
    
print(Solution().convertBST(TreeNode(4, TreeNode(1, TreeNode(0), TreeNode(2, None, TreeNode(3))), TreeNode(6, TreeNode(5), TreeNode(7, None, TreeNode(8))))))  # 30
            
    