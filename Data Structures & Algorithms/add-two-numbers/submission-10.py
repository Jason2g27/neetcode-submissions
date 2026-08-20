# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode()
        cur = dummy
        while l1 != None or l2 != None or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            sum = val1 + val2 + carry
            carry = sum // 10
            sum = sum % 10
            cur.next = ListNode(sum)
            cur = cur.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        return dummy.next