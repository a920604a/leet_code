---
title: 2. Add Two Numbers
tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/add-two-numbers/)

## solution

#### option 1 - iterative
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(-1), *ans = ret;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ret->next = new ListNode(sum%10);
            ret = ret->next;
            carry = sum/10;
        }
        return ans->next;
    }
};
```

#### option 2 - recursive
```c++
class Solution {
public:
    ListNode* addTwo(ListNode* l1, ListNode*l2, int carry){
        if(!l1 && !l2 && carry == 0) return nullptr;
        
        ListNode * node;
        if(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            node = new ListNode(sum%10);
            sum/=10;
            node->next = addTwo(l1, l2, sum);
        }
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        ret->next = addTwo(l1, l2, 0);
        return ret->next;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)` function call