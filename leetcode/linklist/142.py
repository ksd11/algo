# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        slow = self.moveForward(slow, 1)
        fast = self.moveForward(fast, 2)
        while slow != fast:
            # 无环
            if not fast or not fast.next:
                return None
            slow = self.moveForward(slow, 1)
            fast = self.moveForward(fast, 2)

        pos1 = slow
        pos2 = head
        while pos1 != pos2:
            pos1 = self.moveForward(pos1, 1)
            pos2 = self.moveForward(pos2, 1)
        return pos1


    def moveForward(self, head: Optional[ListNode], step: int) -> Optional[ListNode]:
        for _ in range(step):
            if not head:
                return None
            head = head.next
        return head