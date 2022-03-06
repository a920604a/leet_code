---
title: 1290. Convert Binary Number in a Linked List to Integer

tags:  
    - Linked List
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)


## solution

#### option 1 - recursive
```c++
class Solution {
public:
    int ret = 0;
    void preorder(ListNode * head){
        if(!head) return ;
        ret<<=1;
        ret+=head->val;
        preorder(head->next);
    }
    int getDecimalValue(ListNode* head) {
        preorder(head);
        return ret;
    }
};
```



#### option 2 - iterative
```c++
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        for(;head;head=head->next){
            sum<<=1;
            sum+=head->val;
        }
        return sum;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`