'''
Author: yuan
Date: 2021-07-14 21:53:16
LastEditTime: 2021-07-14 22:27:01
FilePath: /leet_code/Python/142_LinkedListCycleII.py
'''
"""
Author: yuan
Date: 2021-07-14 21:53:16
LastEditTime: 2021-07-14 21:53:16
FilePath: /leet_code/Python/142_LinkedListCycleII.py
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                break

        if fast == None or fast.next == None:
            return None

        slow = head
        while slow != fast:
            fast = fast.next
            slow = slow.next
        return slow
