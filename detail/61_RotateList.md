---
title: 61. Rotate List

tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rotate-list/)
## solution

#### option 1 

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
    int getSize(ListNode* node){
        int size = 0;
        for(;node;node=node->next) size++;
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *ret = new ListNode(-1);
        int size = getSize(head);
        int n = size - k%size;
        ListNode *p = head;
        while(n--) p=p->next;
        // avoid 第一元素即為head
        if(p==nullptr) p = head;
        ListNode *newhead = p;
        while(size--){
            ret->next = p;
            ret=ret->next;
            if(p->next == nullptr) p=head;
            else p=p->next;
        }
        ret->next= nullptr;
        return newhead;
    }
};
```



#### option 2 - cycle

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        
        ListNode *p = head;
        int len = 1;
        // 串列長度
        while(p->next){
            p = p->next;
            len++;
        }
        p->next = head; // 串列變成cycle
        cout<<"length of list: "<<len<<endl;
        
        ListNode * start = head;
        // 決定起點
        int n = len-k%len;
        while(n){
            start = start->next;
            n--;
        }
        cout<<"start's value: "<<start->val<<endl;
        ListNode *res = start;
        //決定終點
        len--;
        while(len){
            start = start->next;
            len--;
        }
        start->next = nullptr;
        
        
        return res;
        
    }
};
```




## analysis
- time complexity `O(n)`
- space complexity `O(1)`