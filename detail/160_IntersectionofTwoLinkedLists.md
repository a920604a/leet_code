---
title: 160. Intersection of Two Linked Lists
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/intersection-of-two-linked-lists/)

## solution
#### option 1
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a!=b){
            if(!a) a= headB;
            else a= a->next;
            if(!b) b = headA;
            else b=b->next;
        }
        return a;
    }
};
```
#### option 2
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1. 是否有相同終點以判斷是否有交集
        // 2. 如果有交集，讓長串列先走幾步
        int lenA = 0, lenB= 0;
        ListNode *a = headA, *b = headB;
        while(a){
            a=a->next;
            lenA++;
        }
        while(b){
            b=b->next;
            lenB++;
        }
        // no cycle
        if(a!=b) return nullptr;
        ListNode *fast = (lenA>=lenB)?headA:headB;
        ListNode *slow = (lenA<lenB)?headA:headB;
        int n = abs(lenA-lenB);
        while(n--) fast = fast->next;
        while(fast!=slow){
            slow=slow->next;
            fast = fast->next;
        }
        return slow; 
    }
};
```
## analysis 
- time complexity `O(n)`
- space complexity `O(1)`