---
title: 2074. Reverse Nodes in Even Length Groups
tags:  
    - Linked List
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)

## solution


```c++
class Solution {
public:
    int k =0;
    
    ListNode* reverseN(ListNode *l,ListNode *r){
        ListNode *pre = new ListNode(-1), *cur =l;
        pre->next = l;
        while(cur->next !=r){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return pre->next;
    }
    int getSize(ListNode *head){
        int size=0;
        for(;head;head=head->next) size++;
        return size;
    }
    ListNode* reverseEvenLengthGroups(ListNode *head, int size){
        
        if(!head) return nullptr;
        ListNode *a = head, *b =head;
        k++;
        int n = min(size,k);
        size -=k;
        int c = 0;
        while(n--){
            if(b==nullptr) return head;
            b=b->next;
            c++;
        }
        if(c%2==0){
            ListNode* newhead = reverseN(a,b);
            a->next = reverseEvenLengthGroups(b, size);
            return newhead;
        }
        else{
            ListNode *p =a;
            while(p->next !=b) p=p->next;
            p->next = reverseEvenLengthGroups(b, size);
            return a;
        }
    
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int size = getSize(head);
        return reverseEvenLengthGroups(head, size);
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`