# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        n = len(preorder)
        index = {e: i for i, e in enumerate(inorder)}

        def build(prel, prer, inl, inr):
            if prel > prer: return None
            rt = preorder[prel]
            id = index[rt]
            lsz = id - inl

            root = TreeNode(rt)
            root.left = build(prel + 1, prel + lsz, inl, id - 1)
            root.right = build(prel + lsz + 1, prer, id + 1, inr)
            return root

        return build(0, n - 1, 0, n - 1)