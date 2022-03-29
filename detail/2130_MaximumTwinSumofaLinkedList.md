---
title: 2130. Maximum Twin Sum of a Linked List
tags:  
    - Linked List 
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)


## solution
#### option 1 - recursive
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
    ListNode *left ;
    int maxTwinSum;
    void traverse(ListNode *right){
        if(!right) return;
        // postorder
        traverse(right->next);
        
        maxTwinSum = max(maxTwinSum, left->val + right->val);
        left = left->next;
        
    }
    int pairSum(ListNode* head) {
        // must be even length
        // Palindrome
        
        // init.
        left = head;
        maxTwinSum =0;
        traverse(head);
        return maxTwinSum;
    }
};
```
#### option 2 - iterative

```c++
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> sta;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next ){
            fast = fast->next->next;
            slow =slow->next;
        }
        fast = slow;
        int ret =0;
        while(slow){ sta.push(slow->val); slow=slow->next;}
        
        while(head!=fast){
            ret = max(sta.top()+ head->val , ret);
            head = head->next;
            sta.pop();
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- sparse complexity `O(n)`