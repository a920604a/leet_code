---
title: 662. Maximum Width of Binary Tree
tags:
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-width-of-binary-tree/)

## solution
需要用一個整數紀錄最左邊與最右邊的節點的

- overflow
因為同一層最左邊的節點會基於跟節點的值去往上疊加
```c++
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
        // 最左邊與最右邊非空的節點
        // bfs 變形
        // 需要用一個整數紀錄最左邊與最右邊的節點的
        queue<pair<TreeNode *,int> > q;
        q.push(make_pair(root, 1));
        int width = 0;
        while(!q.empty()){
            int size = q.size();
            int l = q.front().second, r;
            for(int i=0;i<size;++i){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                if(i==size-1) r = p.second;
                if(p.first->left) q.push(make_pair(p.first->left, p.second*2));
                if(p.first->right) q.push(make_pair(p.first->right, p.second*2+1));
            }
            width = max(width, r-l+1);
            
        }
        return width;
        
    }
};
```

#### option 1
`if(i==0) l = p.second;`, `(p.second-l)` 確保不會overflow
確保同一層最左邊的空節點，應該為0 
> to make the id starting from zero
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
        // 最左邊與最右邊非空的節點
        // bfs 變形
        // 需要用一個整數紀錄最左邊與最右邊的節點的位置
        queue<pair<TreeNode *,long> > q;
        q.push(make_pair(root, 0));
        int width = 0;
        while(!q.empty()){
            int size = q.size();
            long l ,r;
            for(int i=0;i<size;++i){
                
                pair<TreeNode*, long> p = q.front();
                q.pop();
                if(i==0) l = p.second;
                if(i==size-1) r = p.second;
                if(p.first->left) q.push(make_pair(p.first->left, (p.second-l)*2));
                if(p.first->right) q.push(make_pair(p.first->right, (p.second-l)*2+1));

            }
            width = max(width, (int)(r-l+1));
            
        }
        return width;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`

