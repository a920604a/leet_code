---
title: 39. Combination Sum

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/combination-sum/)

找出所有組合總和為target 的子序列，可以重複選取，但每組組合必須唯一。
## sloution

- 用遞迴暴力求解，遍歷每種可能，終止條件`target<0`
- 因為可以重複，所以每次調用`bracktracking(candidates, target - candidates[i], path, ret, i)` 而不是`l+1`。

- version 1 
```c++
class Solution {
public:
    void bracktracking(vector<int>& candidates,int target, vector<int> & path, vector<vector<int>>& ret, int l ){
        
        if(target<0) return;
        if(target ==0){
            ret.push_back(path);
            return;
        }
        for(int i=l;i<candidates.size(); ++i){
            path.push_back(candidates[i]);
            bracktracking(candidates, target - candidates[i], path, ret, i);
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>  ret;
        vector<int> path;
        bracktracking(candidates, target, path, ret, 0);
        return ret;
    }
};
```

- version 2 sorting 
```c++
class Solution {
public:
    void bracktracking(vector<int>& candidates,int target, vector<int> & path, vector<vector<int>>& ret, int l ){
        // 終止條件
        if(target<0) return;
        if(target ==0){
            ret.push_back(path);
            return;
        }
        for(int i=l;i<candidates.size(); ++i){
            if(target - candidates[i]<0) return ; //sort
            path.push_back(candidates[i]);
            // 因為可重複拿取同一元素
            bracktracking(candidates, target - candidates[i], path, ret, i);
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //sort
        vector<vector<int>>  ret;
        vector<int> path;
        bracktracking(candidates, target, path, ret, 0);
        return ret;
    }
};
```
## analysis
- time complexity `O(len(nums)^M)`, M is the height of our recursive
- space complexity `L` , L is the longest combination