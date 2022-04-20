---
title: 173. Binary Search Tree Iterator
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-search-tree-iterator/)

## solution
#### option 1 - STL to store
事先先拜訪過各節點並存下來，再用一個指標指向當前位置
```c++
class BSTIterator {
private:
    vector<int> nums;
    int cur =0;
public:
    BSTIterator(TreeNode* root) {
        preorder(root);
        
    }
    void preorder(TreeNode *root){
        if(!root) return;
        preorder(root->left);
        nums.push_back(root->val);
        preorder(root->right);
    }
    int next() {
        return nums[cur++];
    }
    
    bool hasNext() {
        return cur!=nums.size();
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
        // 以p 為樹根 左半部已經拜訪完畢
        // 從右子樹找下一個拜訪的點，並放入stack
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
- space complexity `O(h)`