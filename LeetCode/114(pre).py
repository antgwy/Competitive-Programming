# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        pre = []
        def preord(rt: TreeNode):
            if rt == None: return
            pre.append(rt)
            preord(rt.left)
            preord(rt.right)

        preord(root)
        sz = len(pre)
        for i in range(1, sz):
            prev, cur = pre[i-1], pre[i]
            prev.left = None
            prev.right = cur