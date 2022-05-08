---
title: 2265. Count Nodes Equal to Average of Subtree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)
## solution 

- 另外建立兩棵樹，分別代表原先的樹
    - 節點數
    - 總和
```c++
class Solution {
public:
    TreeNode * Sumtree(TreeNode *root){
        if(!root) return nullptr;
        // postorder
        TreeNode *ret = new TreeNode(0);
        if(root->left){
            ret->left = Sumtree(root->left);
            ret->val += ret->left->val;
        }
        if(root->right) {
            ret->right = Sumtree(root->right);
            ret->val += ret->right->val;
        }
        ret->val += root->val;
        return ret;
    }
    TreeNode * CountNode(TreeNode *root){
        if(!root) return nullptr;
        TreeNode *ret = new TreeNode(1);
        if(root->left){
            ret->left = CountNode(root->left);
            ret->val += ret->left->val;
        }
        if(root->right){
            ret->right = CountNode(root->right);
            ret->val += ret->right->val;
        };
        return ret;
        
    }
    void postorder(TreeNode* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
        
    }
    void averageOfSubtree(int &ret , TreeNode* root, TreeNode *sum, TreeNode * count){
        if(!root) return ;
        if(sum->val/ count->val == root->val) ret++;
        averageOfSubtree(ret, root->left, sum->left, count->left);
        averageOfSubtree(ret, root->right, sum->right, count->right);
        
    }
    int averageOfSubtree(TreeNode* root) {
        // Node(node->val), number of node, sum
        TreeNode *sum = Sumtree(root);
        // postorder(sum);
        TreeNode *count = CountNode(root);
        // cout<<endl;
        // postorder(count);
        int ret = 0;
        averageOfSubtree(ret,root, sum, count);
        return ret;
    }
};
```

- 簡化
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
    int cnt = 0;
    pair<int,int> dfs(TreeNode *root){
        if(!root) return {0,0};
        auto left = dfs(root->left), right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int count = 1 + left.second + right.second;
        if(root->val == sum / count) cnt++;
        return {sum, count};
        
    }
    int averageOfSubtree(TreeNode* root) {
        auto p = dfs(root);
        return cnt;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`