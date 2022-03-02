---
title: 47. Permutations II
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/permutations-ii/)

## solution


#### option 1 - sorting
```c++
class Solution {
public:
    vector<vector<int>> ret;
    void traverse(vector<int> & nums, vector<int> &path, vector<bool> & visited){
        // 終止條件，抵達樹的葉子部分
        if(path.size() == nums.size()){
            ret.push_back(path);
            return;
        }
        for(int i=0; i<nums.size() ;++i){
            // avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;
            if(visited[i]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            traverse(nums, path, visited);
            visited[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // avoid duplicates
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        traverse(nums, path, visited);
        return ret;

    }
};
```


#### option 2 - set
```c++
class Solution {
public:
    void traverse(vector<int>& nums, vector<int> & path, set<vector<int>> & ret, vector<bool> visited){
        if(path.size() == nums.size()){
            ret.insert(path);
            return;
        }
        for(int i=0;i<nums.size() ; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            traverse(nums, path, ret, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        traverse(nums, path, ret, visited);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
```