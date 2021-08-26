class Solution
{
public:
    int numDistinct(string s, string t)
    {

        //      -   r   a   b   b   b   i   t
        //-     1   1   1   1   1   1   1   1
        //r     0   1   1   1   1   1   1   1
        //a     0   0   1   1   1   1   1   1
        //b     0   0   0   1   2   3   3   3
        //b     0   0   0   0   1   3   3   3
        //i     0   0   0   0   0   0   3   3
        //t     0   0   0   0   0   0   0   3

        int mod = 1e+9;
        int m = s.size(), n = t.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; ++j)
            dp[0][j] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[j - 1] == t[i - 1])
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
                else
                    dp[i][j] = dp[i][j - 1] % mod;
            }
        }
        return dp[n][m];
    }
};