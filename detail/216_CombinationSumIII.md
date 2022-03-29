---
title: 216. Combination Sum III

tags:  
    - backtracking
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/combination-sum-iii/)

給定`k`、`n` 找出所有和為n，長度為k的有效組合，其元素只能落在1到9區間，且數字必須唯一，不能重複取。

## sloution

```c++
class Solution {
public:
    void backtracking(int k, int target, vector<int>& path, vector<vector<int>>& ret, int l){
        if(path.size() > k) return;
        if(path.size() ==k){
            if(target==0) ret.push_back(path);
            return;
        }
        for(int i=l;i<=9;++i){
            if(target -i<0) return;
            path.push_back(i);
            backtracking(k, target-i, path, ret,i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        backtracking(k, n, path, ret, 1);
        return ret;
    }
};
```

## analysis
- time complexity `O(len(nums)^M)`, M if theight of our recursive
- space complexity `L` , L is the longest combination