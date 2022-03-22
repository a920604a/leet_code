---
title: 996. Number of Squareful Arrays
tags:  
    - math
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/number-of-squareful-arrays/)

## solution
```c++
class Solution {
public:
    int ans ;
    vector<bool> visited;
    void dfs(vector<int> & nums, vector<int> & path){
        if(path.size() == nums.size()){
            ans++;
        }
        
        for(int i=0;i<nums.size();++i){
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;
            if(visited[i] ) continue;
            
            if(!path.empty()){
                double root = sqrt(nums[i]+path.back());
                if(root- floor(root)!= 0 ) continue;
            }
            
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path);
            path.pop_back();
            visited[i] = false;
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> path;
        visited = vector<bool>(nums.size(), false);
        dfs(nums, path);
        return ans;
        
    }
};
```
