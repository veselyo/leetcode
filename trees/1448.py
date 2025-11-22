# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    numGood = 0
    INT_MIN = -(2**31)

    def dfs(self, node, currMax):
        if node is None:
            return

        if currMax <= node.val:
            self.numGood += 1

        currMax = max(currMax, node.val)

        self.dfs(node.left, currMax)
        self.dfs(node.right, currMax)

    def goodNodes(self, root: TreeNode) -> int:
        self.dfs(root, self.INT_MIN)

        return self.numGood