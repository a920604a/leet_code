---
title: 143. Reorder List

tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reorder-list/)

## solution 


#### option 1 - reverse Linked Lists
1. two pointer to find the middle node
2. reverse the second list 
3. merge two lists

```c++
class Solution {
public:
    ListNode * reverseList(ListNode *head){
        ListNode *pre = new ListNode(-1), *cur = head;
        pre->next= head;
        while(cur->next){
            ListNode *post = cur->next;
            cur->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return pre->next;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head, *pre = slow;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow =slow->next;
        }
        if(fast) {
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        // reverse slow
        ListNode * head2 = reverseList(slow);
        
        ListNode *ans = new ListNode(-1), *ret = ans;
        ret->next = head;
        while(head || head2){
            if(head){
                ret->next = head;
                head = head->next;
                ret =ret->next;
            }
            if(head2){
                ret->next = head2;
                head2 = head2->next;
                ret = ret->next;
            }
        }
        head = ans->next;
    }
};
```


#### option 2 - stack

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode *>sta;
        ListNode *p = head;
        while(p){
            sta.push(p);
            p=p->next;
        }
        p=head;
        int size = (sta.size()-1)/2;
        while(size-- > 0 ){
            ListNode *post = p->next;
            p->next = sta.top();
            sta.pop();
            p->next->next = post;
            p=post;
            
        }
        sta.top()->next = nullptr;
        
    }
};
```
## analysis
- option 1 
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`