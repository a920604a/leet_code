---
title: 300. Longest Increasing Subsequence

tags:  
    - dp
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-increasing-subsequence/)

給定一個整數陣列，找出最遞增子序列。


## solution
#### option 1 - dp
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        //  10  9   2   5   3   7   101 18
        //  1   1   1   1   1   1   1   1
        //  1   1   1   2   2   3   4   4
        
        int ret = 1;
        for(int i=1;i<n;++i){
            // 每次確定第 ith 最長子序列
            for(int j=0;j<i;++j){
                if(nums[i] > nums[j] ) dp[i] = max(dp[i], dp[j]+1);
            }
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};
```

#### option 2 - *Binary Search 
更多可以參考`patience sorting`


```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //      10  9   2   5   3   7   101 18
        //top   0   0   0   0   0   0   0   0  
        //
        int n = nums.size();
        vector<int> top(n,0);
        int piles = 0;
        for(int i=0;i<n;++i){
            int poker = nums[i];
            int l =0, r = piles;
            // 從top 陣列可視範圍 l-r 區間找到poker放入的位置，使得top 是單調遞增陣列
            while(l<r){
                int mid = l + (r-l)/2;
                if(top[mid] == poker ) r= mid;
                else if(top[mid] < poker) l = mid+1;
                else r = mid;
            }
            // 插入的位置不在陣列可視範圍內
            if(l==piles) piles++;
            // 將poker 放進陣列top
            top[l] = poker;
        }
        return piles;
    }
};
```
## analysis
- option 1 - dp
    - time complexity `O(n^2)`
    - space complexity `O(1)`
- option 2 - binary search 
    - time complexity `O(nlogn)`
    - sapcency complexity `O(1)`