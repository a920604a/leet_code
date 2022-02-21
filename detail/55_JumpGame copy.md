---
title: 55. Jump Game

tags:  
    - dp
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/jump-game/)


## solution
dp 維護的是剩餘跳力，剩餘跳力是前一個位置的剩餘跳力 -1`dp[i-1]-1的`，或是前一個位置的最大跳力-1 `nums[i-1]-1` 取最大。如果當前剩餘跳力等於零，代表停在於此，小於零代表跳不到這裏。

#### option 1

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //      2   3   1   1   4
        //dp    0   1   2   1   0
        
        //      3   2   1   0   4
        //dp    0   2   1   0   -1
        int n =nums.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;++i){
            dp[i] = max(dp[i-1]-1, nums[i-1]-1);
            if(dp[i]<0) return false;
            
        }
        return true;
        
    }
};
```

#### option 2 reduce dp 

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //      2   3   1   1   4
        //dp    0   1   2   1   0
        
        //      3   2   1   0   4
        //dp    0   2   1   0   -1
        int n =nums.size();
        int canReach = 0;
        for(int i=1;i<n;++i){
            canReach = max(canReach-1, nums[i-1]-1);
            if(canReach<0) return false;
        }
        return true;
    }
};
```

- greedy
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int canReach = 0;
        for(int i=0;i<n-1;++i){
            canReach = max(canReach, i+nums[i]);
            if(canReach<=i) return false;
        }
        return canReach>=n-1?true:false;
    }
};
```
## analysis
- option 1 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(1)`