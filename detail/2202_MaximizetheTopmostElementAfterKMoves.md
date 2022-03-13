---
title: 2202. Maximize the Topmost Element After K Moves
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - dp
```c++
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
  
        
        int n = nums.size();
        // edge case
        if(k==0) return nums[0];
        if(n==1 && k==1) return -1;
        // [18], k=3 => -1
        if(n==1 && k%2==1) return -1;
        
        // [0], k =1000000000 => 0
        if(k>n){
            int mx = nums[0];
            for(int i:nums) mx = max(i, mx);
            return mx;
        }
        vector<vector<int>> dp(k, vector<int>(2,-1));
        //  pop get
        
        dp[0][0] = nums[0];
        dp[0][1] = nums[1];
        int mx = nums[0];
        for(int i=1;i<k ;++i){
            dp[i][0] = nums[i];
            
            if(i+1<n) dp[i][1] = max(nums[i+1], mx);
            else dp[i][1] = mx;
            mx = max(mx, nums[i]);
        }
        return dp[k-1][1];
    }
};
```


#### option 2 - reduce dp
```c++
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
  
        
        int n = nums.size();
        // edge case
        if(k==0) return nums[0];
        if(n==1 && k==1) return -1;
        // [18], k=3 => -1
        if(n==1 && k%2==1) return -1;
        
        // [0], k =1000000000 => 0
        if(k>n){
            int mx = nums[0];
            for(int i:nums) mx = max(i, mx);
            return mx;
        }
        vector<vector<int>> dp(k, vector<int>(2,-1));
        //  pop get
        
        int dp_0 = nums[0], dp_1 = nums[1];
        int mx = nums[0];
        for(int i=1;i<k ;++i){
            dp_0 = nums[i];
            if(i+1<n) dp_1 = max(nums[i+1], mx);
            else dp_1 = mx;
            mx = max(mx, nums[i]);
        }
        return dp_1;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)` -> `O(1)`
