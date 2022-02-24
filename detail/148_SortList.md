---
title: 148. Sort List

tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-list/)

## solution

#### option 1 - vector 
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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode *p = head;
        vector<int> list;
        while(p){
            list.push_back(p->val);
            p=p->next;
        }
        sort(list.begin(), list.end());
        int n = list.size();
        ListNode *ret = new ListNode(list[0]), *ans = ret;
        for(int i=1;i<n;++i){
            ret->next = new ListNode(list[i]);
            ret = ret->next;
        }
        return ans;
    }
};
```

#### option 2 - heap
```c++

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *p = head;
        auto cmp = [](ListNode *a, ListNode *b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        while(p){
            pq.push(p);
            p=p->next;
        }
        ListNode *ret = new ListNode(-1), *ans = ret;
        while(!pq.empty()){
            ret->next = pq.top();
            pq.pop();
            ret = ret->next;
        }
        ret->next = nullptr;
        return ans->next;
    }
};
```
#### option 3 - merge sort
```c++
class Solution {
public:
    ListNode * mergeSort(ListNode *l1, ListNode *l2){
        ListNode * ret = new ListNode(-1), *ans = ret;
        while(l1 && l2){
            if(l1->val < l2->val){
                ret->next = l1;
                l1= l1->next;
            }
            else{
                ret->next = l2;
                l2=l2->next;
            }
            ret = ret->next;
        }
        
        if(l1) ret->next = l1;
        if(l2) ret->next = l2;
        
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        // 1. split each node using slow fast point
        // 2. merge strategy
        if(!head ||!head->next) return head;
        ListNode *slow =head, *fast = head, *pre=head;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        ListNode *a = sortList(head), *b = sortList(slow);
        
        return mergeSort(a,b);
        
    }
};
```

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 2 - heap
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3
    - time complexity `O(nlogn)`
    - space complexity `O(1)`