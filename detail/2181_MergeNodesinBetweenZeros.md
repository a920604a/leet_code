---
title: 2181. Merge Nodes in Between Zeros
tags:
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/merge-nodes-in-between-zeros/)


## solution

```c++
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ret = new ListNode(-1), *ans = ret;
        // spilt lists
        ListNode *cur = head->next;
        int sum = 0;
        while(cur){
            if(cur->val!=0){
                sum+=cur->val;
            }
            else if(cur->val == 0){
                ret->next = new ListNode(sum);
                ret = ret->next;
                sum = 0;
            }
            cur=cur->next;
            
        }
        return ans->next;
    }
};
```

- other version

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ret = new ListNode(-1), *ans = ret;
        // spilt lists
        ListNode *cur = head->next;
        int sum = 0;
        while(cur){
            while(cur && cur->val !=0){
                sum+=cur->val;
                cur=cur->next;
            }
            ret->next = new ListNode(sum);
            ret= ret->next;
            sum = 0;
            cur = cur->next;
        }
        return ans->next;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`