# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        result = []
        queue = deque()
        queue.append(root)

        while len(queue) > 0:
            result.append(queue[-1].val)

            queue_copy = queue.copy()
            queue.clear()
            while queue_copy:
                parent = queue_copy.popleft()
                if parent.left:
                    queue.append(parent.left)
                if parent.right:
                    queue.append(parent.right)

        return result