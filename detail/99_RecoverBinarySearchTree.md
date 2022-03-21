---
title: 99. Recover Binary Search Tree
tags:
    - backtracking
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/recover-binary-search-tree/)

## solution
#### option 1 - STL to store
```c++
class Solution {
public:
    void traverse(TreeNode *root, vector<TreeNode*>& list, vector<int>& vals) {
        if(!root) return ;
        
        traverse(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        traverse(root->right, list, vals);
        
    }
    void recoverTree(TreeNode* root) {
        // 只會有兩個節點放錯
        // 遍歷變存下來在對調
        vector<TreeNode*> list;
        vector<int> vals;
        traverse(root, list, vals);
        sort(vals.begin(), vals.end());      
        
        for(int i=0;i<list.size() ;++i){
            list[i]->val = vals[i];
        }
    }
};
```
#### option 2 - swap
因為只會有兩個節點放錯位置且inorder遍歷應該是有序的，故先找到哪兩個節點在交換

```c++
class Solution {
public:
    TreeNode *prev = nullptr, *a = nullptr, *b = nullptr;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(!a) a = prev;
            b = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(a->val,b->val);
        
    }
};
```


#### option 3 - Morris traverse
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(1)`
