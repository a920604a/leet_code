---
title: 230. Kth Smallest Element in a BST

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

> Follow up 中說假設該 BST 被修改的很频繁

## solution

> follow up 必須先建立一個樹其值存該節點下包含(自己)節點。
#### option 1 - dfs in-order recursive
用inorder 拜訪每個節點，每拜訪一個節點 `k--`，直到`k=0`時，便返回節點的值

```c++
class Solution {
public:
    void inorder(TreeNode* root, int& k, int &ret){
        if(!root) return;
        
        inorder(root->left, k, ret);
        k--;
        if(k==0) {
            ret = root->val;
            return ;
        }
        
        inorder(root->right, k, ret);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ret = -1;
        inorder(root,k, ret);
        return ret;
    }
};
```
> 也可以inorder traverse方式拜訪節點並存在vector ，最後在`return vector[k];` 即可


#### option 2 dfs in-order iterative
需要一個stack ，將當下拜訪到的節點的左子樹都每一個節點push 進去stack
如果拜訪到的是空節點，那則會從stack 頂部取得拜訪節點。


```c++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> sta;
        TreeNode * p = root;
        while(p || !sta.empty()){
            while(p){
                sta.push(p);
                p=p->left;
            }
            p = sta.top();
            sta.pop();
            k--;
            if(k==0) return p->val;
            p=p->right;
        }
        return -1;
    }
};
```

#### option 3 
- 由於BST 特性，可以快速定位第k小的是在左右子樹。
- 先計算左子樹有多少節點，在判斷要往左子樹還是右子樹去尋找還是當前節點。

```c++
class Solution {
public:
    int count(TreeNode* node) {
        if(!node) return 0;
        return 1+count(node->left)+count(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int lcount = count(root->left);
        if(k<=lcount) return kthSmallest(root->left, k);
        else if(k==lcount+1) return root->val;
        return kthSmallest(root->right, k-lcount-1);
    }
};
```
## analysis
- option 1
    - time complexity `O(n)` 
    - space complexity `O(h)`
- option 2
    - time complexity `O(n)` 
    - space complexity `O(h)`
- option 3
    - time complexity `O(n)` for best case, `O(n^2)` for worst case
    - space complexity `O(h)`