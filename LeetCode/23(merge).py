# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def mergetwo(self, a, b):
        if not a or not b: return a if a else b
        head = ListNode()
        tail = head
        pa, pb = a, b
        while pa and pb:
            if pa.val < pb.val:
                tail.next = pa
                pa = pa.next
            else:
                tail.next = pb
                pb = pb.next
            tail = tail.next
        
        tail.next = pa if pa else pb
        return head.next

    def merge(self, lists, l, r):
        if l == r: return lists[l]
        if l > r: return None
        mid = (l + r) // 2
        return self.mergetwo(self.merge(lists, l, mid), self.merge(lists, mid + 1, r))

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        return self.merge(lists, 0, len(lists) - 1)