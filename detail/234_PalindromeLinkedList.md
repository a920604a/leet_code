---
title: 234. Palindrome Linked List
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/palindrome-linked-list/)

## solution
##### option 1 - iterative
```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // iterative + stack
        stack<int> sta;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast =fast->next->next;
        }
        while(slow){
            sta.push(slow->val);
            slow = slow->next;
        }
        fast = head;
        while(!sta.empty() && fast->val==sta.top()){
            sta.pop();
            fast = fast->next;
        }
        return sta.empty(); 
    }
};
```

##### option 2 - recursive

```c++
class Solution {
public:
    ListNode *left;
    bool traverse(ListNode *right){
        if(!right) return true;
        
        bool ret = traverse(right->next);
        if(left->val != right->val) return false;
        left = left->next;
        return ret ;
    }
    bool isPalindrome(ListNode* head) {
        // recursive
        left = head;
        return traverse(head);
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
