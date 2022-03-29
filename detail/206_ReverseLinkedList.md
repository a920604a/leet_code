---
title: 206. Reverse Linked List

tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-linked-list/)



reverse linked list

## solution



#### option 1 - iterative
需要三個個指標

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = nullptr, *cur = head, *post = head->next;
        while(post){
            cur->next = pre;
            pre = cur;
            cur = post ;
            post = post->next;
        }
        cur->next = pre;
        return cur;
    }
};
```
- another version 
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = nullptr, *cur = head;
        while(cur->next){
            ListNode *post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post ;
        }
        cur->next = pre;
        return cur;
    }
};
```
- other version
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = new ListNode(-1), *cur = head;
        pre->next = head;
        while(cur->next){
            ListNode *post = cur->next;
            cur->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return pre->next;
    }
};
```
#### option 2 - recursive
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;;
        return node;
        
    }
};
```
## analysis
- time complexity `O(n)`
- solution complexity `O(n)`
