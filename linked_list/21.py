# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        new_list = None
        new_list_root = None
        ptr1 = list1
        ptr2 = list2

        while(ptr1 is not None or ptr2 is not None):
            new_node = ListNode()
            if ptr2 is None:
                new_node.val = ptr1.val
                ptr1 = ptr1.next
            elif ptr1 is None:
                new_node.val = ptr2.val
                ptr2 = ptr2.next
            elif ptr1.val <= ptr2.val:
                new_node.val = ptr1.val
                ptr1 = ptr1.next
            else:
                new_node.val = ptr2.val
                ptr2 = ptr2.next
            
            if new_list_root is None:
                new_list_root = new_node

            if new_list is not None:
                new_list.next = new_node
            new_list = new_node

        return new_list_root