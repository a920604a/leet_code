class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // option 1 dp O(MN) space and O(MN) time
        int m = text1.size(), n = text2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (text2[i - 1] == text1[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};