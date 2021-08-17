class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {

        int ret = INT_MAX;
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];

        vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
        //  2               =   2   +   +   +
        //  3   4           =   5   6   +   +
        //  6   5   7       =   11  10  11
        //  4   1   8   3   =   14  11  18  14

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {

                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                if (i == n - 1)
                    ret = min(ret, dp[i][j]);
            }
        }

        return ret;
    }
};