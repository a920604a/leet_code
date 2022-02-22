---
title: 2095. Delete the Middle Node of a Linked List
tags:  
    - Linked List 
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## solution

```c++
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode * pre = head, * slow = head, *fast = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = slow->next;
        return head;
    }
};s
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`