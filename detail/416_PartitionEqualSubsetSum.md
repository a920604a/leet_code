---
title: 416. Partition Equal Subset Sum
tags:  
    - backtracking
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/partition-equal-subset-sum/)

## solution


#### option 1 - dfs
```c++
class Solution {
public:
    vector<bool> visited;
    bool traverse(vector<int> & nums, int sum ,int cur, int target, int k ){
        if(k==2) return true;
        if(sum > target) return false;
        if(sum==target){
            k++;
            return traverse(nums, 0,0, target, k);
        }
        
        for(int i=cur;i<nums.size() ; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            if(traverse(nums, sum+nums[i], i+1, target, k)) return true;
            visited[i] = false;
            
        }
        return false;
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for(int n:nums) total+=n;
        if(total%2==1) return false;
        visited = vector<bool>(n, false);
        // cout<<total;
        return traverse(nums, 0, 0, total/2, 0);
    }
};
```

#### option 2 - dp

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for(int n:nums) total+=n;
        
        if(total%2==1) return false;
        total/=2;
        // vector<bool> dp(total/2,0);
        vector<vector<bool>> dp(n+1, vector<bool>(total+1,false));
        // 
        //  0   1   2   3   4   5   6   7   8   9   10  11
        //  t   f   f   f   f   f   f   f   f   f   f   f
        //1 t   t   f   f   f   f   f   f   f   f   f   f   
        //5 t   t   f   f   f   t   t   f   f   f   f   f
        //11t   t   f   f   f   t   t   f   f   f   f   t
        //5 t   t   f   f   f   t   t   f   f   f   t   t
        
        for(int i=0;i<n+1;i++) dp[i][0] = true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<total+1;j++){
                if(j >= nums[i-1]) dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp.back().back();
    }
};
```

#### option 3 - reduce dp
```c++

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for(int n:nums) total+=n;
        
        if(total%2==1) return false;
        total/=2;
        vector<bool> dp(total+1,false);
        // 
        //  0   1   2   3   4   5   6   7   8   9   10  11
        //  t   f   f   f   f   f   f   f   f   f   f   f
        //1 t   t   f   f   f   f   f   f   f   f   f   f   
        //5 t   t   f   f   f   t   t   f   f   f   f   f
        //11t   t   f   f   f   t   t   f   f   f   f   t
        //5 t   t   f   f   f   t   t   f   f   f   t   t
        
        //  0   1   2   3   4   5
        //  t   f   f   f   f   f   
        //1 t   t
        //2 t
        //5 t
        dp[0] = true;
        for(int i=1;i<n+1;i++){
            for(int j = total;j>-1;j--){
                if(j>=nums[i-1]) dp[j] = dp[j] | dp[j-nums[i-1]];
                
            }
        }
        return dp.back();
    }
};

```
## analysis