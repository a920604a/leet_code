---
title: 647. Palindromic Substrings
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/palindromic-substrings/)

## solution
```c++
class Solution {
public:
    int countSubstrings(string s) {
        //
        
        
        //  a   a   a
        //a 1   1   1
        //a     1   1
        //a         1
        

        //  b   a   b   a   b
        //b 1   0   1   0   1        
        //a     1   0   1   0     
        //b         1   0   1
        //a             1   0   
        //b                 1
        int ret = 0;
        int n= s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;++i) dp[i][i] = true;
        ret +=n;
        for(int i=n-2;i>-1 ; i--){
            for(int j=i+1;j<n;++j){
                if(s[i] == s[j]) {
                    if(j==i+1) dp[i][j] = true;
                    else if(dp[i+1][j-1]) dp[i][j] =true;
                }
                
                if(dp[i][j]) ret++;
            }
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`