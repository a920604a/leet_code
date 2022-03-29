---
title: 46. Permutations
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/permutations/)


## solution
#### option 1 - dfs
`if(find(path.begin(), path.end(), nums[i])!=path.end()) continue;` 可以用一組陣列代替`if(visited[i] = true) conitnue;`
```c++
class Solution {
public:
    void traverse(vector<int>& nums, vector<int>&path, vector<vector<int>> & ret){
        if(path.size() == nums.size()){
            ret.push_back(path);
            return;
        }
        
        for(int i=0;i<nums.size() ;++i){
            if(find(path.begin(), path.end(), nums[i])!=path.end()) continue;
            path.push_back(nums[i]);
            traverse(nums, path, ret);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        traverse(nums, path, ret);
        return ret;
    }
};
```
```c++
class Solution {
public:
    vector<vector<int>> ret;
    vector<bool> visited;
    void dfs(vector<int> & nums, vector<int> & path){
        if(path.size() == nums.size()){
            ret.push_back(path);
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, path);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        visited = vector<bool> (nums.size(), false) ;
        dfs(nums, path);
        return ret;      
    }
};
```


#### option 2 - math
```c++

class Solution {
public:
    void traverse(vector<int>& nums,  vector<vector<int>> & ret, int s){
        if(s == nums.size()){
            ret.push_back(nums);
            return;
        }
        
        for(int i=s;i<nums.size() ;++i){
            swap(nums[i], nums[s]);
            traverse(nums, ret, s+1);
            swap(nums[i], nums[s]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ret;
        traverse(nums,ret, 0);
        return ret;
    }
};
```

## analysis
- time complexity `O(n)` n 節點個數
- space complexity `O(n)` n 節點個數