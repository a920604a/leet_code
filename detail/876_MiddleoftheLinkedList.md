---
title: 876. Middle of the Linked List
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/middle-of-the-linked-list/)

## solution
```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next ){
            fast = fast->next->next;
            slow= slow->next;
        }
        return slow;
        
    }
};
```
## analysis
- time complexity `O(n)`
- speed complexity `O(1)`