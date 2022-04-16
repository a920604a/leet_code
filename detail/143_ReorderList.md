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
    ListNode* reverse(ListNode *head){
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        while(head->next){
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return pre->next;
    }
    void reorderList(ListNode* head) {
        if(!head ||!head->next) return;
        int size = 0;
        for(ListNode *p = head;p;p=p->next) size++;
        ListNode *a = head, *b = head, *pre = nullptr;
        int mid = size/2;
        while(mid--){
            pre =b;
            b=b->next;
        }
        pre->next = nullptr;
        ListNode *r  = reverse(b);
        ListNode * p = a;
        a=a->next;
        while(a || r){
            if(r){
                p->next = r;
                r=r->next;
                p=p->next;
            }
            if(a){
                p->next = a;
                a=a->next;
                p=p->next;
            }
        }
        p->next = nullptr;
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

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        stack<ListNode *> sta;
        ListNode * p =head;
        while(p){
            sta.push(p);
            p=p->next;
        }
        ListNode *cur = head, *post = head->next;
        while(sta.top()!=post){
            cur->next = sta.top();
            sta.pop();
            cur=cur->next;
            
            if(sta.top()==post) break;
            cur->next = post;
            cur=cur->next;
            post=post->next;
        }
        cur->next = sta.top();
        cur->next->next= nullptr;
        
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