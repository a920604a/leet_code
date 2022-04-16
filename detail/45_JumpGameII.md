---
title: 45. Jump Game II
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
    int jump(vector<int>& nums) {
        //  2   3   1   1   4
        //      1   1   
        //      1   1   2   2
        //      1   1   2
        
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<=i+nums[i] && j<n; ++j){
                dp[j] = min(dp[i]+1,  dp[j]);
            }
        }
        
        return dp[n-1];
    }
};
```
```c
#define min(a,b) (a<b)?a:b

int jump(int* nums, int numsSize){
    
    int *dp = malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;++i) *(dp+i) = 10001;

    //  2   3   1   1   4
    //  0   1   1   +   +
    //  0   1   1      
    *dp = 0;
    for(int i=0;i<numsSize;++i){
        for(int j = i+1;j<=i+*(nums+i) && j<numsSize ;j++){
            *(dp+j) = min(1+*(dp+i), *(dp+j));
        }
    }
    
    return *(dp+numsSize-1);

}
```

#### option 2 - greedy
```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int lastReach = 0;
	    int reach = 0;
        int step = 0;
        int n = nums.size();
        for(int i=0;i<=reach && i< n; ++i){
            if(i>lastReach){
                // update;
                step++;
                lastReach = reach;
            }
            reach = max(reach, nums[i]+i);
            
        }
        if(reach <n-1) return 0;
        return step;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`