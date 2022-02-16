# 24. Swap Nodes in Pairs

###### tags: `leetcode` `Linked List`

## [problem](https://leetcode.com/problems/swap-nodes-in-pairs/)



## solution
- cheat
modify value of the next node
```c++
class Solution {
public:
    
    ListNode* swapPairs(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode *cur = head;
        while(cur && cur->next){
            int val = cur->val;
            cur->val = cur->next->val;
            cur->next->val = val;
            cur = cur->next->next;
        }
        return head;
    }
};
```
##### option 1 - merge policy
可以看作一條奇數索引的list與偶數索引的list 從頭merge two list
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode *odd = head, *even = head->next, *a = odd, *b = even, *newhead = new ListNode(-1), *ret = newhead;
        
        while(odd && even){
            odd->next = even->next;
            odd=odd->next;
            if(odd){
                even->next = odd->next;
                even = even->next;
            }
        }
        // merge two lists
        while(a || b){
            if(b){
                newhead->next = b;
                b=b->next;
                newhead = newhead->next;
            }
            if(a){
                newhead->next =a;
                a=a->next;
                newhead = newhead->next;
            }
        }
        
        return ret->next;
        
        
    }
};
```

##### option 2 - *swap

## analysis
- time complexity `O(n)`
- space complexity `O(1)`