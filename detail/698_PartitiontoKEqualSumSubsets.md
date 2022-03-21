---
title: 698. Partition to K Equal Sum Subsets

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)17. Letter Combinations of a Phone Number


## solution

#### option 1 - dfs , maybe TLE
```c++
class Solution {
public:
    bool backtracking(vector<int>& nums, vector<bool> & visited, int start, int sum, int target, int k){
        if(k==0) return true;
        if(target == sum){
            return backtracking(nums, visited, 0,0,target , k-1);
        }
        
        for(int i=start;i<nums.size() ; ++i){
            if(visited[i] || sum+nums[i] > target) continue;
            sum+=nums[i];
            visited[i] = true;
            if(backtracking(nums, visited, i+1,sum, target, k) ) return true;
            sum-=nums[i];
            visited[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(int n:nums) total +=n;
        if(total%k!=0) return false;
        vector<bool> visited(n, false);
        total/= k;
        return backtracking(nums, visited, 0, 0, total, k);
    
    }
};
```
