---
title: 740. Delete and Earn
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/delete-and-earn/)

## solution
這就是變形的強盜問題`198. House Robber`
```c++
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        // 3    4   2
        
        //  0   0   2   3   4
        //  0   0   2   3   6
        
        //  0   0   4   9   4   
        //  0   0   4   9   9
        
        int n = nums.size();
        vector<int> ret(10001, 0);
        for(int n :nums) ret[n]+=n;
        int ans = 0;
        for(int i=2;i<10001;++i){
            ret[i] = max(ret[i-2]+ret[i] , ret[i-1]);
        }
        return ret[10000];
    }
};
```

## analysis
