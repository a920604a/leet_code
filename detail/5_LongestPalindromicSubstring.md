---
title: 5. Longest Palindromic Substring

tags:  
    - Two Pointers
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-palindromic-substring/)

最長回文子字串
## solution
#### option 1 - two pointers
Manacher's algorithm is
- 利用雙索引，從拜訪到的字元，當拜訪到字元，相鄰字元都一樣，則向左向右擴散
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int l =0,r = 0, n =s.size(),  start = 0, len = 0;
        for(int i=0;i<n;){
            l=r=i;
            while(r+1<n && s[r] == s[r+1]) r++;
            i = r+1;
            
            while(l>0 && r<n-1 && s[l-1] == s[r+1]){
                l--;
                r++;
            }
            if(r-l+1>len){
                len = r-l+1;
                start = l;
            }
        }
        return s.substr(start, len);
    }
};
```
#### option 2 - *dp

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        
        // dp 
        int n =s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        //  b   a   b   a   d
        //b 1   
        //a     1   0   1
        //b         1   0   0
        //a             1   0
        //d                 1

        int start = 0, len = 1;
        for(int i=n-1;i>-1 ; i--){
            dp[i][i] = 1;
            for(int j=i+1;j<n;++j){
                // ex: "tt" 
                if(s[i] == s[j] && j-i==1){
                    dp[i][j] = 1;
                }
                // ex: babab , dp[i+1][j-1]確保 aba 是回文，才將i往左一格 j 往右一格 
                else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                }
                if(dp[i][j]  && len< j-i+1){
                    len = j-i+1;
                    start =i;
                }
            }
        }
        return s.substr(start, len);
    }
};
```
## analysis
- option 1 - two pointers
    - time complexity `O(n^2)`
    - space complexity `O(1)`
