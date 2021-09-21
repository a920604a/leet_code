# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        cur = ListNode()
        ret = cur
        while l1 or l2:
            summary = carry
            if l1:
                summary += l1.val
                l1 = l1.next
            if l2:
                summary += l2.val
                l2 = l2.next

            cur.next = ListNode(int(summary % 10))
            carry = summary / 10
            cur = cur.next

        if int(carry) != 0:
            cur.next = ListNode(int(carry))

        return ret.next
