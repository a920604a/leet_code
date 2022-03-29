---
title: 142. Linked List Cycle II
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/linked-list-cycle-ii/)

## solution
two pointer ，slow fast pointers 用於linked list檢查是否包含環
當fast 追上slow 代表有環，之後一個從起點開始跑，領一個從相遇位置開始跑，讚次相遇則是在環的起點。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *slow =head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr;
        fast = head;
        while(slow!=fast){
            fast= fast->next;
            slow= slow->next;
        }
        return slow;
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`