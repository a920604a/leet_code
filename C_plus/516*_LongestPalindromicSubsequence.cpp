class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // option 1 dp
        // if s[i] == s[j] dp[i][j] = 2+ dp[i+1][j-1]
        // else  dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        //    b b b a b
        //
        // b  1 0 0 0 0     1 2 3 3 4
        // b  0 1 0 0 0     0 1 2 2 3
        // b  0 0 1 0 0  => 0 0 1 1 3
        // a  0 0 0 1 0     0 0 0 1 1
        // b  0 0 0 0 1     0 0 0 0 1

        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};