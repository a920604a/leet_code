---
title: 237. Delete Node in a Linked List
tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## solution 
```c++
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
    
}
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`