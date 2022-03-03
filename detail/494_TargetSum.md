---
title: 494. Target Sum
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution
- backtracking
> `O(2^N)` time 
```c++
class Solution {
public:
    vector<string> ret;
    void backtracking(vector<int>& nums, int i,string  path, int sum, int target){
        if(i==nums.size()){
            if(sum == target) ret.push_back(path);
            return;
        }
        backtracking(nums, i+1, path+"+"+to_string(nums[i]), sum+nums[i], target);
        backtracking(nums, i+1, path+"-"+to_string(nums[i]), sum-nums[i], target);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        string path;
        backtracking(nums, 0, path,0, target);
        return ret.size();
        
        
    }
};
```

#### option 1 - backtracking
```c++
class Solution {
public:
    int ret =0;
    void backtracking(vector<int>& nums, int i, int sum, int target){
        if(i==nums.size()){
            if(sum == target) ret++;
            return;
        }
        
        backtracking(nums, i+1, sum+nums[i], target);
        backtracking(nums, i+1,  sum-nums[i], target);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        backtracking(nums, 0,0, target);
        return ret;
        
    }
};
```
#### option 2 - memo pattern
```c++
class Solution {
public:
    unordered_map<string, int>  memo;
    int backtracking(vector<int>& nums, int i, int sum, int target){
        if(i==nums.size()){
            if(sum == target)  return 1;
            return 0;
        }
        string key = to_string(i)+ "," + to_string(sum);
        
        if(memo.find(key)!=memo.end()) return memo[key];
        int val = 0;
        val+=backtracking(nums, i+1,  sum+nums[i], target);
        val+=backtracking(nums, i+1,  sum-nums[i], target);

        return memo[key] = val;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return backtracking(nums, 0,0, target);        

    }
};
```
## analysis