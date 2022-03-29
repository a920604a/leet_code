---
title: 19. Remove Nth Node From End of List

tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)


## solution 
- 因為只允許遍歷一遍 one pass，利用快慢指標
- two pointer 不知道串列長度 iterative 

先將快指標向右移動 `n` 個單位
慢指標與快指標一起向右移動，直到快指標到達串列尾部，慢指標的下一個節點則為要移除的節點，`slow->next = slow->next->next;` 移除掉。


```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = new ListNode(-1), *fast = slow, *ret = slow;
        slow->next = head;
        while(n){
            fast = fast->next;
            n--;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return ret->next;
    }
};
```

- recursive 

```c++
class Solution {
public:
    ListNode *helper(ListNode* node, int n , int &cur)
    {
        if(!node){
            cur = 0;
            return nullptr;
        }
        node->next = helper(node->next, n, cur);
        if(++cur == n){
            return node->next;
        }
        return node;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cur = -1;
        return helper(head, n, cur);
    }
};
```
## analysis

- time complexity `O(n)`
- space complexity `O(1)`