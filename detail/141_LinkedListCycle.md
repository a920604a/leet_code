---
title: 141. Linked List Cycle
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/linked-list-cycle/)

## solution
two pointer ，slow fast pointers 用於linked list檢查是否包含環

#### option 1
```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        ListNode *cur = head;
        while(cur){
            if(s.find(cur)!=s.end()) return true;
            s.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};
```
#### option 2 - Two pointers
```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ) return head;
        ListNode *slow =head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) return true;
        }
        return false;        
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`