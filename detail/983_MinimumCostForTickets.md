---
title: 983. Minimum Cost For Tickets
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-cost-for-tickets/)


## solution
```c++
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        //      1   4   6   7   8   20
        //1     2   4   6   8   10  12
        //7     2   4   6   7   9   11
        //30    2   4   6   7   9   11
        
        
        int n = days.size(), m = costs.size();
        vector<int> dp(n+1,0);
        // init
        dp[0] = 0;
        for(int i=1;i<n+1;++i){
            // 確定第 i 天花最少錢
            
            // one day
            dp[i] = dp[i-1] + costs[0];
            for(int j=1;j<=i;++j){
                
                if( days[i-1] - days[j-1] < 7) dp[i] = min(dp[i], dp[j-1] + costs[1]);
                if( days[i-1] - days[j-1] < 30) dp[i] = min(dp[i], dp[j-1] + costs[2]);
            }
        }
        
        return dp.back();
        
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(n)`