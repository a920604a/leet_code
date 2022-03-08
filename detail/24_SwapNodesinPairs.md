---
title: 24. Swap Nodes in Pairs

tags:  
    - Linked List
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/swap-nodes-in-pairs/)

## solution
- cheat
modify value of the next node
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *a = head, *b = head->next;
        while(b){
            // swap adjacent node's value
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
            
            // 前進
            a=b->next;
            if(a) b=a->next;
            // 到盡頭了
            else break;
            // else b =nullptr;
        }
        return head;
    }
};
```
##### option 1 - merge policy
可以看作一條奇數索引的list與偶數索引的list 從頭merge two list
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode *odd = head, *even = head->next, *a = odd, *b = even, *newhead = new ListNode(-1), *ret = newhead;
        
        while(odd && even){
            odd->next = even->next;
            if(even->next) even->next = even->next->next;
            
            // 前進
            odd=odd->next;
            even=even->next;
        }
        while(a|| b){
            if(b){
                newhead->next = b;
                newhead=newhead->next;
                b=b->next;
            }
            if(a){
                newhead->next= a;
                newhead=newhead->next;
                a=a->next;
            }
        }
        return ret->next;
    }
};
```

##### option 2 - *swap

## analysis
- time complexity `O(n)`
- space complexity `O(1)`