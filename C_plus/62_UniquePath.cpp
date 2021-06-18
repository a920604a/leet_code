class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // option 1 dynamic programming
        //         vector<vector<int>> dp(m , vector<int>(n,1));

        //         for(int i=0;i<m;++i){
        //             for(int j=0;j<n;++j){
        //                 if(i==0 || j==0) continue;
        //                 else{
        //                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //                 }
        //             }
        //         }
        //         return dp[m-1][n-1];

        // option 2 dp slove space
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[j] += dp[j - 1];
            }
        }

        // math
    }
};