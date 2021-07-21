class Solution
{
public:
    //1143. Longest Common Subsequence
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        // 相等於 需要刪除多少字符才會變相同
        // 刪除多少字符 也等於 可由求最長公共子序列得知

        int n = word1.size(), m = word2.size();
        int lcs = longestCommonSubsequence(word1, word2);
        return m - lcs + n - lcs;
    }
};