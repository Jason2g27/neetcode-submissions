# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        order = []
        self.dfs(root, order)
        return order[k-1]
    def dfs(self, node, order):
        if node == None:
            return
        self.dfs(node.left, order)
        order.append(node.val)
        self.dfs(node.right, order)


        