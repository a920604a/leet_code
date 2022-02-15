# 19. Remove Nth Node From End of List

###### tags: `leetcode` `Linked List` `Two Pointers`

## [problem](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)


## solution 
利用快慢指標
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