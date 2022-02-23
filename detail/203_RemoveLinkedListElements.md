---
title: 203. Remove Linked List Elements
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/remove-linked-list-elements/)

## solution

```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = new ListNode(-1), *ret = cur;
        cur->next = head;
        while(cur){
            if(cur->next && cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return ret->next;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`