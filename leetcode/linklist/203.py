from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        # 保证head中的val都不等于val
        while head and head.val == val:
            head = head.next

        h = head
        while head and head.next:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next        
        
        return h

head = ListNode(1, ListNode(2, ListNode(6, ListNode(3, ListNode(4, ListNode(5, ListNode(6)))))))

res = Solution().removeElements(head, 6) # 1 -> 2 -> 3 -> 4 -> 5

while res:
    print(res.val)
    res = res.next
