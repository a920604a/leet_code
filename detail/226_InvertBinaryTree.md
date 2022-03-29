---
title: 226. Invert Binary Tree
tags:  
    - bfs
    - backtracking
categories: leetcode
---




## [problem](https://leetcode.com/problems/invert-binary-tree/)

## solution 
#### option 1 - backtracking
- inorder traverse version 

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        // post-order
        
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};
```

- postorder traverse version

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};
```

#### option 2 - bfs

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode * >q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                TreeNode *p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                TreeNode *temp = p->left;
                p->left = p->right;
                p->right = temp;
            }
        }
        return root;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`