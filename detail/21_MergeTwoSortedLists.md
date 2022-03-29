---
title: 21. Merge Two Sorted Lists

tags:  
    - Linked List
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/merge-two-sorted-lists/)

## solution 

- 因為是排序過的list，只要 new 兩個指標分別指向`list1` `list2` 比較大小，小的放進要回傳的串列即可。

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ret = new ListNode(-1), *ans = ret ;
        // compare each node in two lists
        while(list1 && list2){
            if(list1->val < list2->val) {
                ret->next = list1;
                list1=list1->next;
            }
            else{
                ret->next = list2;
                list2=list2->next;
            }
            ret = ret->next;
        }
        if(list1) ret->next = list1;
        if(list2) ret->next = list2;
        return ans->next;
    }
};
```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`