---
title: 83. Remove Duplicates from Sorted List
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/)


## solution

#### option 1 - Two Pointers
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *slow = head, * fast = head;
        while(fast){
            if(slow->val !=fast->val){
                slow->next = fast;
                slow = slow=slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
```
- other version
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *ret = new ListNode(-1), *ans = ret;
        ret->next = new ListNode(head->val);
        ret = ret->next;
        head= head->next;
        while(head){
            if(head->val!=ret->val){
                ret->next = head;
                ret =ret->next;
            }
            head= head->next;
        }
        ret->next = nullptr;
        return ans->next;
    }
};
```

#### option 2 - improve option 1
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p = head;
        while(p){
            while(p->next && p->val ==p->next->val) p->next = p->next->next;
            p=p->next;   
        }
        return head;
    }
};
```

#### option 3 - use STL
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        set<int> s;
        ListNode *ret = new ListNode(-1), *ans = ret;
        // 利用set ordered
        for(ListNode *p = head;p;p=p->next) s.insert(p->val);
        
        for(auto iter = s.begin(); iter!=s.end();iter++){
            ret->next = new ListNode(*iter);
            ret= ret->next;
        }
        return ans->next;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`