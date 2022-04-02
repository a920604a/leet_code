---
title: 2221. Find Triangular Sum of an Array
tags:  
    - dp
    - queue
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-triangular-sum-of-an-array/)
## solution

#### option 1 - dp
```c++
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size(), size = n;
        vector<vector<int>> dp(n);
        dp[0] = nums;
        if(n==1) return nums[0];
        for(int i=1;i<n;++i){
            size--;
            dp[i] = vector<int>(size,0);
            for(int j = 0 ;j<size;++j){
                dp[i][j] =(dp[i-1][j] + dp[i-1][j+1])%10;
            }
        }
        return dp.back().back();
        
    }
};
```
#### option 2 - queue
```c++
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size(), size = n;
        queue<int> q;
        for(int n :nums) q.push(n);
        while(q.size()!=1){
            int size = q.size();
            int pre = q.front();q.pop();
            size--;
            for(int i = 0;i<size; ++i){
                int cur = q.front(); q.pop();
                int next = cur;
                q.push((cur+pre)%10);
                pre = cur;
            }
        }
        return q.front();
        
    }
};
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)` `O(n)`

