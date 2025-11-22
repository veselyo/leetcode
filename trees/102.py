# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        currLevel = deque()
        nextLevel = deque()
        result = []

        if root is None:
            return result

        currLevel.append(root)

        while len(currLevel) > 0:
            result.append([node.val for node in currLevel])
            while len(currLevel) > 0:
                parent = currLevel.popleft()
                if parent.left:
                    nextLevel.append(parent.left)
                if parent.right:
                    nextLevel.append(parent.right)

            tmp = currLevel
            currLevel = nextLevel
            nextLevel = tmp
        
        return result