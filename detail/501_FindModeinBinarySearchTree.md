---
title: 501. Find Mode in Binary Search Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-mode-in-binary-search-tree/)



## solution
#### option 1 - two pass
用array 隨著inorder拜訪樹的每個節點並存下來。便是遞增陣列
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
    void inorder(TreeNode *root, vector<int>& ret ){
        if(!root) return;
        
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        // 1. inorder traverse tree and save each node into array
        inorder(root, ret);
        // 2. 統計個數字與其頻率
        unordered_map<int,int> freq;
        for(int a:ret) freq[a]++;
        // 3. select freqency of mode in array
        int count = 0, vote = 1, n=ret.size();
        for(int i=1;i<n;++i){
            if(ret[i] == ret[i-1]){
                vote++;
            }
            else{
                count = max(vote, count);
                vote = 1;
            }
        }
        count = max(vote, count);
        // 4. collect mode 
        vector<int> ans;
        for(auto f:freq){
            if(f.second == count) ans.push_back(f.first);
        }
        
        return ans;
    }
};
```

#### option 2 - one pass
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
    vector<int> arr;
    int curCount = 0, maxCount = 0;
    TreeNode * prev = nullptr;
    void inorder(TreeNode *root){
        if(!root) return;
        
        inorder(root->left);
        
        // process
        if(prev == nullptr){
            // 初始化
            curCount = 1;
            maxCount = 1;
            arr.push_back(root->val);
            prev = root;
        }
        else{
            if(root->val == prev->val){
                curCount++;
                if(curCount == maxCount){
                    arr.push_back(root->val);
                }
                else if(curCount > maxCount){
                    arr.clear();
                    maxCount = curCount;
                    arr.push_back(root->val);
                }
            }
            // 當拜訪到與先前不同數值的節點
            else{
                maxCount = max(curCount, maxCount);
                curCount =1;
                if(curCount == maxCount){
                    arr.push_back(root->val);
                }
            }
            prev = root;
            
        }
        
        
        inorder(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return arr;
        
        
    }
};
```




