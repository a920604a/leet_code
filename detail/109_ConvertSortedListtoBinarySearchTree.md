---
title: 109. Convert Sorted List to Binary Search Tree
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## solution

```c++
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *pre = head;
        while(fast && fast->next){
            pre = slow;
            fast =fast->next->next;
            slow = slow->next;
        }
        pre->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        if(slow->next) root->right = sortedListToBST(slow->next);
        return root;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`