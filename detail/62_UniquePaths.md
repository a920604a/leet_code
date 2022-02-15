# 62. Unique Paths

###### tags: `leetcode` `dp`

## [problem](https://leetcode.com/problems/unique-paths/)


## solution

#### option 1 - dp
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        //  1   1   1   1   1   1   1   
        //  1   2   3   4   5   6   7   
        //  1   3   6   10  15  21  28
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

#### option 2 - reduce dp
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        //  1   1   1   1   1   1   1   
        //  1   2   3   4   5   6   7   
        //  1   3   6   10  15  21  28
        vector<int> dp(n,1);
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[j] += dp[j-1];
            }
        }
        return dp.back();
    }
};
```

#### option 3 use math
## analysis
- option 1
    - time complexity `O(n*m)`
    - space complexity `O(n*m)`
- option 2
    - time complexity `O(n*m)`
    - space complexity `O(n)`