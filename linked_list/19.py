# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0

        curr_node = head
        while curr_node:
            curr_node = curr_node.next
            length += 1

        if n > length:
            return None

        curr_node = head
        idx = length - n

        if idx == 0:
            return head.next

        curr_idx = 0

        while curr_idx < idx - 1:
            curr_node = curr_node.next
            curr_idx += 1

        prev_node = curr_node
        curr_node = curr_node.next

        if curr_node.next == None:
            prev_node.next = None
        else:
            prev_node.next = curr_node.next

        return head