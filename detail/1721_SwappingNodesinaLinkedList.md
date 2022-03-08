---
title: 1721. Swapping Nodes in a Linked List
tags:
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)


## solution
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
    int getSize(ListNode * head){
        int size = 0;
        for(;head;head=head->next) size++;
        return size;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        int size = getSize(head);
        int a = k-1;
        ListNode *l=head, *r=head;
        while(a--){
            l=l->next;
        }
        int b = size-k;
        while(b--) r=r->next;
        //swap value
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        return head;
        
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
