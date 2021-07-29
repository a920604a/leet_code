class Solution
{
public:
    vector<vector<int> > memo;
    int dp(vector<vector<int> > &grid, int i, int j)
    {
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (memo[i][j] != -1)
            return memo[i][j];
        memo[i][j] = min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];
        return memo[i][j];

        // return grid[i][j] + min(dp(grid, i-1,j ),  dp(grid, i, j-1) );
    }
    int minPathSum(vector<vector<int> > &grid)
    {

        // option 0 brute force recursive -> time out

        // int m = grid.size(), n = grid[0].size();
        // return dp(grid, m-1, n-1);

        // option 1 重疊子問題 memo pattern up-bottom  O(MN) space and time
        // int m = grid.size(), n = grid[0].size();
        // // 初始化memo
        // memo = vector<vector<int>>(m, vector<int>(n, -1));
        // return dp(grid, m-1, n-1);

        //  option 2 dp bottom-up O(MN) space and time
        //         int m = grid.size(), n = grid[0].size();
        //         vector<vector<int>> dp(grid.begin(), grid.end());

        //         for(int i=1;i<m;++i) dp[i][0] += dp[i-1][0];
        //         for(int j = 1;j<n;++j) dp[0][j] += dp[0][j-1];

        //         for(int i=1;i<m;++i){
        //             for(int j = 1;j<n;++j){

        //                 dp[i][j] += min(dp[i-1][j], dp[i][j-1]) ;
        //             }
        //         }
        //         return dp[m-1][n-1];

        // option 3 reduce dp O(MN) time but O(N) space
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        // 初始化dp
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = grid[0][j] + dp[j - 1];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == 0)
                    dp[j] = dp[j] + grid[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};