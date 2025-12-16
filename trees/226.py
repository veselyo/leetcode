# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def recurse(node):
            if node is None:
                return

            tmp_left = node.left
            node.left = node.right
            node.right = tmp_left

            recurse(node.right)
            recurse(node.left)

        recurse(root)

        return root