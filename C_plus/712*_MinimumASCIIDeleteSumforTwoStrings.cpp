class Solution
{

public:
    int dp(string s1, int i, string s2, int j, vector<vector<int> > &memo)
    {
        int res = 0;
        // base case
        if (i == s1.size() || j == s2.size())
        {
            if (i == s1.size())
            {
                // s1到盡頭了，那s2剩下的都得刪除
                for (; j < s2.size(); ++j)
                    res += (int)s2[j];
            }
            else if (j == s2.size())
            {
                // s2到盡頭了，那s1剩下的都得刪除
                for (; i < s1.size(); ++i)
                    res += (int)s1[i];
            }
            return res;
        }

        if (memo[i][j] != -1)
            return memo[i][j];

        // s1[i] 、 s2[j] 都在最長子序列
        if (s1[i] == s2[j])
            return memo[i][j] = dp(s1, i + 1, s2, j + 1, memo);
        else
        {
            // s1[i] s2[j] 至少一個不在LCS刪一個
            memo[i][j] = min(
                (int)s1[i] + dp(s1, i + 1, s2, j, memo),
                (int)s2[j] + dp(s1, i, s2, j + 1, memo));
        }
        return memo[i][j];
    }
    int minimumDeleteSum(string s1, string s2)
    {
        // 1143. Longest Common Subsequence LCS
        // 583. Delete Operation for Two Strings
        // option 1 memo time out
        // 需要知道刪除的字符是什麼，無法直接用LCS，需要基於原先的LCS去修改。

        // "sea"
        // "eat"
        // 231 332 429
        // 116 217 314
        // -1 116 213

        // int n = s1.size(), m = s2.size();
        // vector<vector<int>> memo(n, vector<int>(m,-1));
        // return dp(s1, 0, s2, 0, memo);

        // option 2 dp
        // "sea"
        // "eat"
        //        e    a    t    = s2
        //   0   101   198  314
        // s 115 216   313  429
        // e 216 115   212  328
        // a 313 212   115   231
        int n = s1.size(), m = s2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= m; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp[n][m];
    }
};