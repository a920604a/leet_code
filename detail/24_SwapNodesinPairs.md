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
##### option 1 - iterative => merge two list
可以看作一條奇數索引的list與偶數索引的list 從頭merge two list
```c++
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
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd = new ListNode(-1), *even = new ListNode(-1);
        ListNode *oddfirst = odd, *evenfirst = even;
        int i=1;
        for(ListNode *p =head;p;p=p->next, i++){
            if(i&1==1){
                odd->next = p;
                odd=odd->next;
            }
            else{
                even->next=p;
                even=even->next;
            }
        }
        odd->next = nullptr;
        even->next = nullptr;
        ListNode *ret = new ListNode(-1), *ans = ret;
        oddfirst = oddfirst->next;
        evenfirst = evenfirst->next;
        while(oddfirst || evenfirst){
            if(evenfirst){
                ret->next = evenfirst;
                evenfirst=evenfirst->next;
                ret = ret->next;
            }
            if(oddfirst){
                ret->next = oddfirst;
                oddfirst=oddfirst->next;
                ret=ret->next;
            }
        }
        return ans->next;
    }
};
```
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *a =head, *b=head->next;
        ListNode *pre = new ListNode(-1), *ans = pre;
        ListNode *temp ;
        while(a || b){
            if(b){
                temp =b;
                if(b->next) b=b->next->next;
                else b = nullptr;
                pre->next = temp;
                pre=pre->next;
                
            }
            if(a){
                temp =a;
                if(a->next) a=a->next->next;
                else a=nullptr;
                pre->next = temp;
                pre=pre->next;   
            }
        }
        pre->next= nullptr;
        return ans->next;
    }
};
```

##### option 2 - recursive can generalize
```c++
class Solution {
public:
    ListNode *reverse(ListNode *l, ListNode *r){
        ListNode *pre = new ListNode(-1);
        pre->next = l;
        while(l->next !=r){
            ListNode *temp = l->next;
            l->next =temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return pre->next;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *a = head, *b = head;
        for(int i=0;i<2;++i){
            if(!b) return head;
            b=b->next;
        }
        ListNode *newhead = reverse(a,b);
        a->next = swapPairs(b);
        return newhead;
        
    }
};
```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`