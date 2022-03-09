---
title: 993. Cousins in Binary Tree
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/cousins-in-binary-tree/)


## solution

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
class Cousin{
public:
    int val;
    int parent;
    int depth;
    Cousin(){
        parent = -1;
    }
    Cousin(int val, int parent, int depth){
        val = val;
        parent = parent;
        depth = depth;
    }
};
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        TreeNode *a = nullptr, *b = nullptr;
        int ia =  -1, ib=-1,depth = 1;
        Cousin *coux = new Cousin(), *couy  = new Cousin();
        queue<TreeNode* > q({root});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode* p= q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                    if(p->left->val == x){
                        coux->val = x;
                        coux->parent= p->val;
                        coux->depth = depth;
                    }
                    else if(p->left->val == y){
                        couy->val = y;
                        couy->parent= p->val;
                        couy->depth = depth;
                    }
                }
                if(p->right){
                    q.push(p->right);
                    if(p->right->val == x){
                        coux->val = x;
                        coux->parent= p->val;
                        coux->depth = depth;
                    }
                    else if(p->right->val == y){
                        couy->val = y;
                        couy->parent= p->val;
                        couy->depth = depth;
                    }
                    
                }
                // check
                if(couy->parent!=-1 && coux->parent!=-1){
                    if( couy->depth == coux->depth && couy->parent!=coux->parent) return true;
                    else return false;
                } 
            }
            depth++;
        }
            // 找不到
        return false;
        
    }
};
```