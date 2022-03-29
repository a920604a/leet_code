---
title: 23. Merge k Sorted Lists

tags:  
    - Linked List
    - Heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/merge-k-sorted-lists/)

## solution 

#### option 1 - merge lists

用for 迴圈遍歷，並兩兩linked list 合併

```c++
class Solution {
public:
    ListNode* mergeLists(ListNode *a, ListNode* b){
        ListNode *ret = new ListNode(-1),*ans = ret;
        while(a && b){
            if(a->val < b->val){
                ret->next = a;
                a = a->next;
            }
            else{
                ret->next = b;
                b = b->next;
            }
            ret = ret->next;
        }
        if(a) ret->next =a;
        if(b) ret->next = b;
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 兩兩合併
        if(lists.empty()) return nullptr;
        ListNode *c = lists[0];
        for(int i=1;i<lists.size() ; ++i){
            c = mergeLists(c, lists[i]);
        }
        return c;
    }
};
```

#### option 2 - heap
建立一個 `priority_queue` 來儲存每個linked list的頭。
在遍歷pq，每次從`priority_queue`取出最小的linked list 頭，從`priority_queue` pop，再儲存linked list head->next。直到`priority_queue` 為空 

`priority_queue` 排序可理解成`return a->val > b->val;`從大排到小，但從尾部開始pop，所以每次取出的是最小的

```c++
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode*b){
            return a->val > b->val;

        };
        priority_queue<ListNode *,vector<ListNode*> , decltype(cmp)> pq(cmp);
        for(ListNode * list :lists){
            if(list) pq.push(list);
        }
        ListNode *ret = new ListNode(-1), *ans = ret;
        while(!pq.empty()){
            ListNode *p = pq.top();
            pq.pop();
            ret->next = p;
            ret = ret->next;
            p=p->next;
            if(p) pq.push(p);
        }
        return ans->next;
    }
};
```

> heap pop `O(logn)`
> heap push `O(logn)`


## analysis 
- option 1 merge
    - time complexity `O(n^2)`
    - space complexity `O(nk)`
- option 2 heap
    - time complexity `O(nlogk)`
    - space complexity `O(n)k`