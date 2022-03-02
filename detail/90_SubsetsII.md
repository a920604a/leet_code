---
title: 90. Subsets II

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution

#### option 1 - sorting

```c++
class Solution {
public:
    void traverse(vector<int>& nums, vector<int>& path, vector<vector<int>>& ret, int s){
        // 關鍵
        ret.push_back(path);
        // 終止條件，s==nums.size()
        
        // 因為不可以重複元素需要有索引
        for(int i=s;i<nums.size();++i){
            // avoid duplicate
            if(i>s && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            traverse(nums, path, ret, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // avoid duplicate
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> path;
        traverse(nums, path, ret, 0);
        return ret;
        
    }
};
```
#### option 2 - set
```c++
class Solution {
public:
    void traverse(vector<int>& nums, vector<int>& path, set<vector<int>>& ret, int s){
        // 關鍵
        ret.insert(path);
        // 終止條件，s==nums.size()
        
        // 因為不可以重複元素需要有索引
        for(int i=s;i<nums.size();++i){
            path.push_back(nums[i]);
            traverse(nums, path, ret, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        vector<int> path;
        traverse(nums, path, ret, 0);
        return vector<vector<int>>(ret.begin(), ret.end());
        
    }
};
```