---
title: 173. Binary Search Tree Iterator
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-search-tree-iterator/)

## solution
事先先拜訪過各節點並存下來，再用一個指標指向當前位置
```c++
class BSTIterator {
private:
    vector<int> vec;
    int cur ;
public:
    void preorder(TreeNode *root){
        if(!root) return;
        preorder(root->left);
        vec.push_back(root->val);
        preorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        preorder(root);
        cur = 0;
    }
    
    int next() {
        return vec[cur++];
    }
    
    bool hasNext() {
        return cur<vec.size();
        
    }
};
```


#### option 2 - stack
```c++
class BSTIterator {
private:
    stack<TreeNode *>sta;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            sta.push(root);
            root= root->left;
        }
    }
    
    int next() {
        TreeNode * p = sta.top();
        sta.pop();
        int ret = p->val;
        if(p->right){
            p=p->right;
            while(p){
                sta.push(p);
                p=p->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return !sta.empty();
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`