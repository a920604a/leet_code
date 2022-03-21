---
title: 508. Most Frequent Subtree Sum
tags:
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/most-frequent-subtree-sum/)

## solution
#### option 1
```c++
class Solution {
public:
    unordered_map<int,int> memo;
    void postorder(TreeNode *root){
        if(!root) return;
        
        postorder(root->left);
        postorder(root->right);
        
        if(root->left) root->val += root->left->val;
        if(root->right) root->val += root->right->val;
        memo[root->val]++;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        vector<pair<int,int>> freq;
        int maxFreq = 0;
        for(auto m:memo){
            maxFreq = max(maxFreq, m.second);
            freq.push_back({m.first, m.second});
        } 
        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(auto f:freq){
            if(f.second ==maxFreq) ans.push_back(f.first);
            else break;
        }
        return ans;
    }
};
```
#### option 2 - optimization option 1
```c++
class Solution {
public:
    unordered_map<int,int> memo;
    vector<int> ans;
    int maxFreq;
    void postorder(TreeNode *root){
        if(!root) return;
        
        postorder(root->left);
        postorder(root->right);
        
        if(root->left) root->val += root->left->val;
        if(root->right) root->val += root->right->val;
        memo[root->val]++;
        
        if(memo[root->val] >= maxFreq){
            if(memo[root->val] > maxFreq) ans.clear();
            ans.push_back(root->val);
            maxFreq = memo[root->val];
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxFreq = 0;
        postorder(root);
        return ans;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`