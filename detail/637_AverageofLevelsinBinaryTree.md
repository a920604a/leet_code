---
title: 637. Average of Levels in Binary Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/average-of-levels-in-binary-tree/)


## solution
```c++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root) return ret;
        queue<TreeNode *> q({root});
        while(!q.empty()){
            int size = q.size();
            double avg = 0;
            for(int i=0;i<size;++i){
                TreeNode *p = q.front();
                q.pop();
                avg+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);                
            }
            ret.push_back(avg/size);
        }
        return ret;
    }
};
```

