---
title: 108. Convert Sorted Array to Binary Search Tree
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

## solution
```c++
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int n = nums.size();
        TreeNode *root = new TreeNode(nums[n/2]);
        vector<int> left(nums.begin(), nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2+1, nums.end());
        root->right = sortedArrayToBST(right);
        root->left = sortedArrayToBST(left);
        return root;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`