# 746. Min Cost Climbing Stairs

###### tags: `leetcode` `dp`

## [problem](https://leetcode.com/problems/min-cost-climbing-stairs/)

## solution

當前位置的花費，是前兩個位置累積的花費加上前兩個位置的花費`min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);`

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //      10  15  20
        //      0   0   15
        
        
        //  1   100 1   1   1   100 1   1   100 1
        //  0   0   1   2   
        int n = cost.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = dp[1] = 0;
        for(int i=2;i<=n;++i){
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        return dp.back();
    }
};
```

## analysis