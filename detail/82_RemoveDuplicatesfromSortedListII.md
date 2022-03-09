---
title: 82. Remove Duplicates from Sorted List II
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)


## solution
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = new ListNode(-101), *ret = slow;
        slow->next = head;
        while(slow->next){
            ListNode * fast = slow->next;
            while(fast->next && fast->next->val ==fast->val ) {
                fast=fast->next;
            }
            if(slow->next ==fast) slow=slow->next;
            else slow->next = fast->next;
        }
        return ret->next;
    }
};
```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`