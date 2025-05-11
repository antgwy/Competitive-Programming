# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        vis = set()
        tmp = headA
        while tmp is not None:
            vis.add(tmp)
            tmp = tmp.next
        
        tmp = headB
        while tmp is not None:
            if tmp in vis: return tmp
            tmp = tmp.next
        
        return None