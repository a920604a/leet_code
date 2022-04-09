---
title: 572. Subtree of Another Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/subtree-of-another-tree/)


## solution

#### option 1
- 遍歷每個節點，並比較當前節點與`subRoot` 是否為同一棵樹，如果是`return true`，反之拜訪當前節點的左右子樹，是否與`subRoot` 同一棵樹，依此類推，直到遇到空節點
```c++
class Solution {
public:
    bool isSameTree(TreeNode *root, TreeNode *sub){
        if(!root && !sub) return true;
        if(!root || !sub) return false;
        if(root->val == sub->val) return isSameTree(root->left, sub->left) && isSameTree(root->right, sub->right);
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```
```c++
class Solution {
public:
    bool isSame(TreeNode *a, TreeNode *b){
        
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val ) return false;
        else return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        bool ret = false;
        if(root->val == subRoot->val) ret =  isSame(root, subRoot);
        return isSubtree(root->left, subRoot ) || isSubtree(root->right, subRoot) || ret;
    }
};
```
#### option 2
將兩棵樹的每個葉子的left child 補上 "#"，並將樹的節點用字串方式相連接，問題就變成字串是否有在另一字串裡。


```c++
class Solution {
public:
    void traverse(TreeNode * root, string &ret){
        if(!root){
            ret.append("#");
            return ;
        }
        // inorder traverse
        ret.append(","+to_string(root->val));
        traverse(root->left, ret);
        traverse(root->right, ret);      
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1, str2;
        traverse(root, str1);
        traverse(subRoot, str2);
        //  string::npos;  表示字串結束位置
        return str1.find(str2)!= string::npos;
    }
};
```
## analysis
- option 1
    - time complexity `O(s*t)` , for each node of `s`, check if it's subtree eaquals `t`
    - space complexity `O(m)` m is height of tree for worst case, `O(logm)` for average case
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)` 
