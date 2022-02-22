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
class Solution {
public:
    ListNode *left ;
    ListNode* traverse(ListNode* right, int &ret){
        if(!right) return nullptr;
        if(!right->next){
            ret = max(ret, right->val+left->val);
            return right;
        }
        
        ListNode *node = traverse(right->next, ret);
        left = left->next;
        ret = max(ret, right->val+left->val);
        return node;
        
        
    }
    int pairSum(ListNode* head) {
        //recursive
        left = head;
        int ret = 0;
        traverse(left,ret);
        
        return ret;
        
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