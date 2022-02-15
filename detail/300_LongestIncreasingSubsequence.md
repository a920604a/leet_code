# 300. Longest Increasing Subsequence

###### tags: `leetcode` `dp`

## [problem](https://leetcode.com/problems/longest-increasing-subsequence/)

給定一個整數陣列，找出最遞增子序列。


## solution

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
            for(int j=0;j<i;++j){
                if(nums[i] > nums[j] ) dp[i] = max(dp[i], dp[j]+1);
                ret = max(ret,dp[i]);
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(1)`